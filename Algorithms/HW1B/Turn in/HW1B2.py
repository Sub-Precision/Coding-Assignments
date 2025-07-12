import time

def timeEfficiency(funcName, args):
    #start timing
    start = time.time()
    # run function
    numbers = funcName(args)
    # end time
    end = time.time()
    totalTime = end - start
    # display results
    print("\tstart':", start, ", 'end':", end, ", 'time efficiency':", totalTime)
    return numbers

def listPrimeNumbers(theMaxNum):
    # code snippet stolen from codingeek.com
    numbers = []
    for val in range(theMaxNum):
        if val > 1:
            for i in range(2, val):
                if (val % i) == 0:
                    break
            else:
                numbers.append(val)
    return numbers

def main():
    # ask user for input
    userInput = int(input("Enter a number for the list of prime numbers:"))
    # display output
    print("List of prime numbers of", userInput, "{")
    # run timing function
    numbers = timeEfficiency(listPrimeNumbers, userInput)
    #display result
    print("\t'result':", numbers)
    print("}")


main()

