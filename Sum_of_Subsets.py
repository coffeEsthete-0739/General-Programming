def subset_sum(arr, target, i=0, subset=[]):
    if sum(subset) == target:
        print(subset)
        return
    if i >= len(arr) or sum(subset) > target:
        return
    subset_sum(arr, target, i+1, subset+[arr[i]])
    subset_sum(arr, target, i+1, subset)

arr = list(map(int, input("Enter elements: ").split()))
target = int(input("Enter target sum: "))
subset_sum(arr, target)
