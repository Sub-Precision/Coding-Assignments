# Program HW1b created by Cade Nichols of class 002 of CSCI 3412 "Algorithms" on 2/5/2023 - ID 107826036

import random
from random import choice

def validator(bannedArray, numArray):
    # repeats this function until a unique number is generated
    while True:
                # guessed random variables
                num4 = random.randrange(9)
                num5 = random.randrange(9)
                num6 = random.randrange(9)
                # generate list with guessed numbers
                guessArray = [num4, num5, num6]
                # test currently guessed array against all previous iterations
                for x in range(len(bannedArray)):
                    # if the guessed array matches any previous guesses
                    # it generates a new set of numbers to test
                    if guessArray == bannedArray[x]:
                        break
                    else:
                        # if it hits the end of the list without matching
                        # it passes the new valid guess
                        if x == len(bannedArray)-1:
                            return guessArray
                        else:
                            # cycles through to test against next iteration of banned entries
                            continue

def main():
    # display expected output text
    print("a) Deterministic brute-force guessing")
    print("algorithm:")
    print()
    # declare variables
    maxCount = 0
    minCount = 10000
    averageCount = 0
    totalGuesses = 0

    # 10k tries
    for y in range(10000):
        # generate numbers to guess
        num1 = random.randrange(9)
        num2 = random.randrange(9)
        num3 = random.randrange(9)
        # put them into a list
        numArray = [num1, num2, num3]
        # populate banned array with 1 for len() functions
        bannedArray = [(10, 10, 10)]
        # 10k try limit
        for x in range(10000):
            # call to validator function
            guessArray = validator(bannedArray, numArray)
            # if guessed correctly add up total number of guesses it took to get here
            if numArray == guessArray:
                totalGuesses = totalGuesses + (x + 1)
                # test if new high score reached
                if (x + 1) > maxCount:
                    maxCount = x + 1
                    # test if new low score reached
                elif minCount > (x + 1):
                    minCount = x + 1
                break
            else:
                # if guess is wrong, add this combination to a blacklist
                bannedArray.append(guessArray)
                # exception for if try limit is exceeded
                if x == 9999:
                    print("case was bailed out")
                    totalGuesses += 10000
                    break
    # computes the average
    averageCount = totalGuesses / 10000

    # this second half of the project is almost exactly the same
    # save for removing all of the stipulations from the first half

    print("\t Number of Tries: 10000")
    print("\t The highest number of guesses")
    print("\t in a try", maxCount)
    print("\t The lowest number of tries:", minCount)
    print("\t The average number of tries:")
    print("\t", averageCount)

    # generate random numbers to guess
    # display expected output text
    print("b) Pure random guessing algorithm")
    print()
    # reset all values
    maxCount = 0
    minCount = 10000
    averageCount = 0
    totalGuesses = 0
    for y in range(10000):
        num1 = random.randrange(9)
        num2 = random.randrange(9)
        num3 = random.randrange(9)
        for x in range(10000):
            # guessed random variables
            num4 = random.randrange(9)
            num5 = random.randrange(9)
            num6 = random.randrange(9)
            # only this is new and all it does is compare all 3 numbers at the same time
            if num1 == num4 and num2 == num5 and num3 == num6:
                totalGuesses = totalGuesses + (x + 1)
                if (x + 1) > maxCount:
                    maxCount = x + 1
                elif minCount > (x + 1):
                    minCount = x + 1
                break
            else:
                if x == 9999:
                    print("case was bailed out")
                    totalGuesses += 10000
                    break
    averageCount = totalGuesses / 10000


            

    print("\t Number of Tries: 10000")
    print("\t The highest number of guesses")
    print("\t in a try", maxCount)
    print("\t The lowest number of tries:", minCount)
    print("\t The average number of tries:")
    print("\t", averageCount)


main()