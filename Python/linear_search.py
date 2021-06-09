def linear_search(list,target):
    """
    Returns the index position of the target is found, else returns None
    """
    for i,val in enumerate(list):
        if val == target:
            return i
    return None

def verify(index):
    if index is not None:
        print(f"Target found at index: {index}")
    else:
        print("Target not found in list")
numbers = list(range(1,11))
result = linear_search(numbers, 12)
verify(result)
result = linear_search(numbers, 6)
verify(result)