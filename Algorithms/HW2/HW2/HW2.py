import time
import copy

count = 0
mergeCount = 0
insertionCount = 0
# Function to do insertion sort
# stolen from the lecture
def insertionSort(A): 
    global insertionCount
    # Traverse through 1 to len(A) 
    for j in range(1, len(A)): 
        key = A[j]  # saved the A[j] to key
        # Move A[0..j-1], if greater than key, to one before their current position 
        i = j-1
        while i >=0 and A[i] > key : 
            A[i+1] = A[i]
            i -= 1
            insertionCount += 1
        A[i+1] = key

# stolen from the lecture
def mergeSort(alist):
    global mergeCount
    if len(alist)>1:
        # dividing step
        mid = len(alist)//2
        lefthalf = alist[:mid]
        righthalf = alist[mid:]
        mergeSort(lefthalf)
        mergeSort(righthalf)
        # merging two halves at each step
        i=0; j=0; k=0
        while i < len(lefthalf) and j < len(righthalf):
            mergeCount += 1
            if lefthalf[i] <= righthalf[j]: # removed equals
                alist[k]=lefthalf[i]
                i=i+1
            else:
                alist[k]=righthalf[j]
                j=j+1
            k=k+1 # removed indent for this line
        # Handling left-overs
        while i < len(lefthalf):
            alist[k]=lefthalf[i]
            i=i+1
            k=k+1
        while j < len(righthalf):  
            alist[k]=righthalf[j]
            j=j+1
            k=k+1

# stolen from my HW1B past homework
def timeEfficiency(funcName, args):
    #start timing
    start = time.time()
    # run function
    funcName(args)
    # end time
    end = time.time()
    totalTime = end - start
    # display results
    print("\tstart':", start, ", 'end':", end, ", 'time efficiency':", totalTime)

def main():
    # global variables for counting
    global insertionCount
    global mergeCount
    finalArray = []
    fileNames = ["rand1000.txt", "rand10000.txt", "rand100000.txt" , "rand250000.txt" , "rand500000.txt", "rand1000000.txt" ]
    for name in fileNames :
        # open file
        with open(name) as outfile:
            for line in outfile:
                # this creates one continuous list of all numbers in the file
                finalArray.extend(map(int, line.split()))
        #creating deep copies as to not overwrite the unordered list
        mergeArray = copy.deepcopy(finalArray)
        insertionArray = copy.deepcopy(finalArray)
        # printing results to screen and calling sorting functions
        print("Time efficiency of Merge sort with", len(finalArray), "integers.")
        timeEfficiency(mergeSort, mergeArray)
        print("Time efficiency of Insertion sort with", len(finalArray), "integers.")
        timeEfficiency(insertionSort, insertionArray)
        # displaying comparison count
        print("Merge sort # of comparisons:", mergeCount)
        print("Insertion sort # of comparisons:", insertionCount)
        # resetting arrays and counters for next file
        finalArray = []
        mergeCount = 0
        insertionCount = 0

main()
