def binary_search(list,target):
    """
    Requires Sorted algorithm
    O(log(n))
    """
    first = 0
    last = len(list)-1

    while first<=last:
        midpoint = (first+last)//2
        if list[midpoint] == target:
            return midpoint
        elif list[midpoint] < target:
            first = midpoint+1
        else:
            last = midpoint-1
    return None

def verify(index):
    if index is not None:
        print(f"Target found at index: {index}")
    else:
        print("Target not found in list")

numbers = list(range(1,11))
result = binary_search(numbers, 12)
verify(result)
result = binary_search(numbers, 6)
verify(result)