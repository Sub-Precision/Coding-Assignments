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

# this is the decorator function
def timeEfficiency(func, args):
    def wrapper():
        #start timing
        start = time.time()
        # run function
        func(args)
        # end time
        end = time.time()
        totalTime = end - start
        # display results
        print("\tstart':", start, ", 'end':", end, ", 'time efficiency':", totalTime)
        return func(args)
    return wrapper

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

# had to get rid of main() to bypass a referencing local variable error i kept getting

#ask user for input
userInput = int(input("Enter a number for the list of prime numbers:"))
# display output
print("List of prime numbers of", userInput, "{")
# run timing function
listPrimeNumbers = timeEfficiency(listPrimeNumbers, userInput)
numbers = listPrimeNumbers()
#display result
print("\t'result':", numbers)
print("}")
