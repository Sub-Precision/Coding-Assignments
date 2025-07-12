import heapq


def radixSort(arr, maxDigit):
    for i in range(maxDigit):
        buckets = [[] for j in range(10)]
        for num in arr:
            digit = (num // 10**i) % 10
            buckets[digit].append(num)
        arr = [num for bucket in buckets for num in bucket]
    return arr


def countingSort(arr, exp):
    n = len(arr)
    output = [0] * n
    count = [0] * 10
    for i in range(n):
        idx = (arr[i] // exp)
        count[idx % 10] += 1
    for i in range(1, 10):
        count[i] += count[i-1]
    for i in range(n-1, -1, -1):
        idx = (arr[i] // exp)
        output[count[idx % 10] - 1] = arr[i]
        count[idx % 10] -= 1
    for i in range(n):
        arr[i] = output[i]
    return arr


def bucketSort(arr):
    n = len(arr)
    buckets = [[] for j in range(n)]
    for num in arr:
        idx = num // 10
        buckets[idx].append(num)
    for i in range(n):
        buckets[i] = sorted(buckets[i])
    return [num for bucket in buckets for num in bucket]


def mergeSortedLists(sublists):
    merged_list = []
    heap = []
    # initialize heap with first element from each sublist
    for i in range(len(sublists)):
        if sublists[i]:
            heapq.heappush(heap, (sublists[i][0], i))
    # merge sublists using heap
    while heap:
        val, idx = heapq.heappop(heap)
        merged_list.append(val)
        sublists[idx] = sublists[idx][1:]
        if sublists[idx]:
            heapq.heappush(heap, (sublists[idx][0], idx))
    return merged_list


def main():
    nums = []
    # read in integers from file
    with open("rand1000000.txt", "r") as f:
        for line in f:
            # this creates one continuous list of all numbers in the file
            nums.extend(map(int, line.split()))

    # split into 100 sublists of equal size
    num_sublists = 100
    sublist_size = len(nums) // num_sublists
    if len(nums) % num_sublists != 0:
        nums += [0] * (sublist_size * num_sublists - len(nums))
    sublists = [nums[i:i+sublist_size] for i in range(0, len(nums), sublist_size)]

    # sort half of sublists using radix sort and counting sort
    for i in range(num_sublists // 2):
        sublists[i] = radixSort(sublists[i], 6)

    # sort other half of sublists using bucket sort
    for i in range(num_sublists // 2, num_sublists):
        sublists[i] = bucketSort(sublists[i])

    # merge all sorted sublists using O(n log k) time algorithm
    sorted_nums = mergeSortedLists(sublists)

    # print first 10 elements of sorted list
    print(sorted_nums)

main()