import re
def main():
    userInput = input("Enter file a file name: ")
    finalString = []
    dupeWords = ['']
    dupeWordsCount = [0]


    
    with open(userInput) as outfile:
        for line in outfile:
            for words in line:
                # putting all lines of text into one continuous list
                finalString.append(words)
    # this line i used from geeksforgeeks.org, modified to fit my program
    finalString = ''.join([str(newString) for newString in finalString])
    # formatting to all lowercase and removing \n to avoid complications
    finalString = finalString.lower()
    finalString = finalString.strip()
    # this line i also found was discovered in techiedelight.com, modified for my program
    s = re.sub('[,,.]', '', finalString)
    finalString = s
    # more formatting
    newArray = finalString.split()
    count = [0] * len(newArray)
    for x in range(len(newArray)):
        for y in range(len(newArray)):
            if (newArray[x] == newArray[y]):
                count[x] += 1
    for x in range(len(newArray)):
        toFind = max(count)
        if toFind == 0:
            break
        toPrint = count.index(toFind)
        print(newArray[toPrint], ":", toFind)
        indices = [i for i, j in enumerate(count) if j == toFind]
        for y in range(len(indices)):
            count[indices[y]] = 0




main()