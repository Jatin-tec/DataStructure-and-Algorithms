lis = [1, 4, 5, 8, 14, 39, 40 , 77]

def BinarSearch(Arr, element):
    low = 0 
    high = len(Arr) - 1

    while(high>=low):
        mid = int(low + high /2)

        if(Arr[mid]==element):
            print("Element found in index: ", mid)
            return 1

        if(Arr[mid]<element):
            low = mid + 1

        else:
            high = mid - 1

    print("Element not Found!")


BinarSearch(lis, 4)