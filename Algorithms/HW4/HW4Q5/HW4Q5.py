def max_heapify(array, i):
    length = len(array) - 1  # for termination condition check
    largest = i
    while True:
        left = 2 * i
        right = 2 * i + 1
        if left <= length and array[i] < array[left]:
            largest = left
        if right <= length and array[largest] < array[right]:
            largest = right
        if largest != i:
            array[i], array[largest] = array[largest], array[i]
            i = largest
        else:
            break
    return array

def test():
    array = [4, 10, 3, 5, 1]
    i = 1  # index of element to heapify
    output = max_heapify(array, i)
    print(output)


test()
