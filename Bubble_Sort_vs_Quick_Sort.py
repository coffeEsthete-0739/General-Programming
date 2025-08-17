import time

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[0]
    left = [x for x in arr[1:] if x <= pivot]
    right = [x for x in arr[1:] if x > pivot]
    return quick_sort(left) + [pivot] + quick_sort(right)

arr1 = list(map(int, input("Enter array: ").split()))
arr2 = arr1.copy()

start = time.time()
bubble_sort(arr1)
print("Bubble Sort Time:", time.time() - start)

start = time.time()
arr2 = quick_sort(arr2)
print("Quick Sort Time:", time.time() - start)
