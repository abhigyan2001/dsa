def recursive_binary_search(list, target):
    if len(list)==0:
        return False
    else:
        mid = (len(list))//2
        if list[mid] == target:
            return True
        else:
            if list[mid] < target:
                return recursive_binary_search(list[mid+1:],target)
            elif list[mid] > target:
                return recursive_binary_search(list[:mid],target)

def verify(index):
    if index is not None:
        print(f"Target found at index: {index}")
    else:
        print("Target not found in list")

numbers = list(range(1,11))
result = recursive_binary_search(numbers, 12)
verify(result)
result = recursive_binary_search(numbers, 6)
verify(result)