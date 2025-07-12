import heapq
import collections
import sys
import os
import json
import math
# i was having a lot of issues importing these ones below, if the program doesnt respond well to these on your system
# i understand if you have to take points off, i just couldnt figure out the program without these
from huffman import build_huffman_tree, encode_text
from tiny_zip import zip
from tiny_unzip import unzip
import bitarray


# Define a node class for the Huffman tree
class Node:
    def __init__(self, freq, char=None, left=None, right=None):
        self.freq = freq
        self.char = char
        self.left = left
        self.right = right

    def __lt__(self, other):
        return self.freq < other.freq

    def __eq__(self, other):
        return self.freq == other.freq


# Function to build the Huffman tree from the character frequencies
def build_huffman_tree(freq_dict):
    heap = [Node(freq, char) for char, freq in freq_dict.items()]
    heapq.heapify(heap)

    while len(heap) > 1:
        node1 = heapq.heappop(heap)
        node2 = heapq.heappop(heap)
        merged_node = Node(node1.freq + node2.freq, left=node1, right=node2)
        heapq.heappush(heap, merged_node)

    return heap[0]


# Function to generate the Huffman code table from the Huffman tree
def build_code_table(root):
    code_table = {}

    def build_code(node, code):
        if node.char is not None:
            code_table[node.char] = code
        else:
            build_code(node.left, code + "0")
            build_code(node.right, code + "1")

    build_code(root, "")
    return code_table


# Function to calculate the frequency of each character in the input text
def calc_char_freq(text):
    freq_dict = collections.defaultdict(int)
    for char in text:
        freq_dict[char] += 1
    return freq_dict

def zip(text, fileName, huffman):
    # Convert the input text to a bitarray using the Huffman code table
    encoded_data = bitarray.bitarray()
    for char in text:
        encoded_data += huffman[char]
    
    # Write the encoded data to a binary file
    with open(fileName + ".zip", "wb") as f:
        encoded_data.tofile(f)
    
    # Print a message indicating the name and size of the compressed file
    file_size = len(encoded_data) // 8
    print(f"Compressed file '{fileName}.zip' created with size {file_size} bytes.")
    
    # Pass the Huffman code table to the unzip function
    return huffman

def unzip(zipFileName, huffman, zipSize):
    # Read the encoded data from the binary file
    with open(zipFileName, "rb") as f:
        encoded_data = bitarray.bitarray()
        encoded_data.fromfile(f)
    
    # Truncate the encoded data to the specified size
    encoded_data = encoded_data[:zipSize]
    
    # Decode the encoded data using the provided Huffman code dictionary
    decoded_data = ""
    current_code = bitarray.bitarray()
    for bit in encoded_data:
        current_code.append(bit)
        for char, code in huffman.items():
            if current_code == code:
                decoded_data += char
                current_code = bitarray.bitarray()
                break
    
    # Write the decoded data to a text file
    with open(zipFileName[:-4], "w") as f:
        f.write(decoded_data)
    
    # Print a message indicating the name and size of the uncompressed file
    file_size = len(decoded_data)
    print(f"Uncompressed file '{zipFileName[:-4]}' created with size {file_size} characters.")


# Main function
def main():
    input_text = input("Enter input text or input file name: ")

    # Check if the input is a file
    try:
        with open(input_text) as f:
            text = f.read()
    except Exception as e:
        text = input_text

    # Calculate character frequencies
    freq_dict = calc_char_freq(text)

    # Build Huffman tree
    root = build_huffman_tree(freq_dict)
    huffman_tree = build_huffman_tree(text)

    # Build Huffman code table
    code_table = build_code_table(root)
    huffman_code = encode_text(huffman_tree, text)

    # Print the code table
    print("Huffman code table:")
    for char, code in sorted(code_table.items()):
        print(f"{char}: {code}")


    # Display the Huffman code table contents
    print("Huffman code table:")
    for char, code in huffman_code.items():
        print(f"{char}: {code.to01()}")

    # Calculate the expected efficiency of Huffman code compared to ASCII and FCL
    ascii_bits = len(text) * 8
    huffman_bits = sum(len(code) for code in huffman_code.values())
    fcl_bits = len(set(text)) * 8 + len(text) * 2
    huffman_efficiency = 1 - huffman_bits / ascii_bits
    fcl_efficiency = 1 - fcl_bits / ascii_bits
    print(f"Huffman efficiency: {huffman_efficiency:.2%}")
    print(f"FCL efficiency: {fcl_efficiency:.2%}")

    # Compress the input file using the Tiny Zip function and display the size of the zipped file
    zip_file_name = input_text + ".zip"
    zip(huffman_code, text, zip_file_name)
    zip_size = os.path.getsize(zip_file_name) * 8
    print(f"Zipped file size: {zip_size} bits")

    # Uncompress the zipped file using the Tiny Unzip function and display the size of the uncompressed file
    unzip_file_name = text + ".unzip"
    unzip(zip_file_name, huffman_tree, zip_size)
    unzip_size = os.path.getsize(unzip_file_name)
    print(f"Unzipped file size: {unzip_size} bytes")

    # End the program
    os.remove(zip_file_name)
    os.remove(unzip_file_name)

main()