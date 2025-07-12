# Program HW1b created by Cade Nichols of class 002 of CSCI 3412 "Algorithms" on 2/5/2023 - ID 107826036

import random

# binary search algorithm heavily modified from geeksforgeeks.org
# parameters include max number, min number, the number to be guessed
# the total counter variable, and the counter variable for a single instance
def binarySearch(lowRange, highRange, x, count, tempCount):
    if highRange >= lowRange:
        midRange = (highRange + lowRange) // 2
        if midRange == x:
            tempCount += 1
            # it does not matter what the number is
            # it just needs to keep track of how many times it loops
            # and returns that number, nothing more
            return tempCount
        elif midRange > x:
            tempCount += 1
            return binarySearch(lowRange, midRange-1, x, count, tempCount)
        else:
            tempCount += 1
            return binarySearch(midRange+1, highRange, x, count, tempCount)
    else:
        print("number is out of range")
        return False

def main():
    # Declare Variables
    count = 0
    # loop the designated number of times
    for x in range(10000):
        # range variable
        numToGuess = random.randrange(1, 1000)
        # reset temporary counter
        tempCount = 0
        # do the binary search algorithm
        finalCount = binarySearch(1, 1000, numToGuess, count, tempCount)
        # add the number of guesses it took
        # and adds it to the pile
        count = finalCount + count
    # computing the average
    averageCount = count / 10000
    # printing the result to the terminal
    print("1. The randum numbers between 1 .. 1k:")
    print("Total Guesses:", count, "Avg:", averageCount)
    # resetting total counter
    count = 0
    # doing it all over again, only difference being range
    for x in range(10000):
        numToGuess = random.randrange(1, 1000000)
        tempCount = 0
        tempCount = binarySearch(1, 1000000, numToGuess, count, tempCount)
        count = count + tempCount
    averageCount = count / 10000
    print("2. The randum numbers between 1 .. 1M:")
    print("Total Guesses:", count, "Avg:", averageCount)

main()
