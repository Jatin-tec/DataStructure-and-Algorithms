Array = [10, 7, 23, 13, 7, 111, 33, 7]

def radixSort(Arr):

    Max = max(Arr)

    exp = 1
    
    while((Max//exp)>0):
        countSort(Arr, exp)
        exp *= 10

def countSort(Arr, exp):
    count = [0] * (10)        
    output = [0] * (len(Arr))

    for i in range(len(Arr)):
        index = Arr[i]//exp
        count[int(index%10)]+=1

    for i in range(len(count)):
        count[i] += count[i-1]

    i = len(Arr)-1
    while i>=0:
        index = Arr[i]/exp
        output[count[int(index%10)] - 1] = Arr[i]   
        count[int(index%10)] -= 1     
        i -= 1 

    for i in range(len(output)):
        Arr[i] = output[i]


print('Before')
print(Array)

radixSort(Array)   

print('After')
print(Array)