Array = [3, 1, 9, 7, 3, 1, 5, 6, 2]

def bubbleSort(Arr):
    for i in range(len(Arr)-1):
        for j in range(len(Arr)-1):
            if Arr[j]>Arr[j+1]:
                Arr[j], Arr[j+1] = Arr[j+1], Arr[j]



print(Array)
bubbleSort(Array)
print(Array)
