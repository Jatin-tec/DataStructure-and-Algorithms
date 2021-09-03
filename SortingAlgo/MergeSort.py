Arr = [10, 7, 23, 13, 22, 53]

def mergeSort(Arr):
    if len(Arr)>1:
        
        mid = len(Arr)//2

        leftArr = Arr[:mid]
        rightArr = Arr[mid:]

        print('left Array : ', leftArr)
        mergeSort(leftArr)

        print('right Array : ', rightArr)
        mergeSort(rightArr)


        i = j = k = 0

        while(i < len(leftArr) and j < len(rightArr)):
            if(leftArr[i]<rightArr[j]):
                print(f'replacing {Arr[k]} with {leftArr[i]} in position {k}')
                Arr[k]=leftArr[i]
                i+=1
                k+=1
            else:
                print(f'replacing {Arr[k]} with {rightArr[i]} in position {k}')
                Arr[k]=rightArr[j]
                j+=1
                k+=1


print('Before sort')
print(Arr)

mergeSort(Arr)

print('After sort')            
print(Arr)