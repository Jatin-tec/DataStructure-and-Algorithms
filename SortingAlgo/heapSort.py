Array = [10, 7, 21 , 22, 23, 24, 2, 0]

def heapify(Arr, size, Max):


    largest = Max
    left = 2*Max + 1
    right = 2*Max + 2

    if (right<size) and (Arr[largest]<Arr[right]):
        largest=right

    if (left<size) and (Arr[largest]<Arr[left]):
        largest=left

    if largest != Max:
        Arr[largest], Arr[Max] = Arr[Max], Arr[largest]

        heapify(Arr, size, largest)
    

def heapSort(Arr):

    i = (len(Arr)//2)-1

    while i>=0:
        heapify(Arr, len(Arr), i)
        i -= 1

    size = len(Arr)-1
    while size>0:
        print('Max heap before swap:')
        print(Array)
        Arr[size], Arr[0] = Arr[0], Arr[size]  
        print('Max heap swaped:')
        print(Array)
        print('')  
        heapify(Arr, size, 0)
        size -= 1

print('Before sort')
print(Array)
heapSort(Array)
print('After sort')
print(Array)