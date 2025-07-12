import copy
import time

def optimizedBubbleSort(array):
    # Declare variables
    lenArray = len(array)
    # for loop to iterate through array elements
    for i in range(lenArray):
        # set default for swapped variable
        swap = False
        for j in range(0, lenArray-i-1):
            # swaps the two compared elements if the prior is greater than the next
            if array[j] > array[j+1]:
                array[j], array[j+1] = array[j+1], array[j]
                swap = True
        # This is what makes the bubblesort optimized, as it stops the process if there was no swap
        if (swap == False):
            break
  
# quicksort implementation pulled from geeksforgeeks.org
# but slightly modified and added my own comments to demonstrate that i understand what it does
# because i am not clever enough to come up with a unique implementation of this code
def partition(array, low, high):
    # choosing last digit as pivot
    pivot = array[high]
    # pointer for greater element
    x = low
    # iterate through array comparing all elements with pivot
    for i in range(low, high):
        if array[i] <= pivot:
            # swap element with pointer
            (array[x], array[i]) = (array[i], array[x])
            # increment pointer if element is smaller than pivot
            x = x + 1
    # swapping pivot with the value in the element pointed to by x
    (array[x], array[high]) = (array[high], array[x])
    # Return partition position
    return x
  
def quickSort(array, low, high):
    if low < high:
        # call partition function to determine and pivot and to semi sort
        # the array where all values below the pivot as to the left 
        # and all values above are on the right of it
        pivot = partition(array, low, high)
        # Recursive call for the numbers greater than previous pivot
        quickSort(array, low, pivot - 1)
        # Recursive call for the numbers less than previous pivot
        quickSort(array, pivot + 1, high)

def timeEfficiency(funcName, arg1, arg2, arg3):
    #start timing
    start = time.time()
    # run function
    funcName(arg1, arg2, arg3)
    # end time
    end = time.time()
    totalTime = end - start
    # display results
    print("\tstart':", start, ", 'end':", end, ", 'time efficiency':", totalTime)

OptimizedK = 100

def QuickBubble(left, right, array):
    if (right - left < OptimizedK):
        optimizedBubbleSort(array)
    else:
        pivot = partition(array, left, right)
        QuickBubble(left, pivot-1, array)
        QuickBubble(pivot+1, right, array)

def main():

    # this is the testing functionality of both optimized bubble sort and quick sort to save time
    # i am putting all parts of Q4 in one file, but i am not doing the extra credit, so it wont be too bad

    # Part A
    # random numbers generated from the internet and copied here
    randomArray = [89, 55, 68, 58, 98, 78, 90, 30, 31, 12, 61, 94, 9, 65, 5, 26, 88, 59, 71, 36]
    optimizedBubbleSort(randomArray)
    print("Optimized bubble sorting test of functionality:")
    print(randomArray)
    print()
    randomArray = [89, 55, 68, 58, 98, 78, 90, 30, 31, 12, 61, 94, 9, 65, 5, 26, 88, 59, 71, 36]
    quickSort(randomArray, 0, len(randomArray) - 1)
    print("Optimized quick sorting test of functionality:")
    print(randomArray)

    # Part D
    finalArray = []
    randomArray = [89, 55, 68, 58, 98, 78, 90, 30, 31, 12, 61, 94, 9, 65, 5, 26, 88, 59, 71, 36]
    with open("rand1000000.txt") as outfile:
            for line in outfile:
                # this creates one continuous list of all numbers in the file
                finalArray.extend(map(int, line.split()))
    size = len(finalArray) - 1
    timeEfficiency(QuickBubble, 0, size, finalArray)
    QuickBubble(0, len(randomArray), randomArray)
    print("Optimized quickBubble sorting test of functionality:")
    
main()
