Array = [10, 7, 21 , 22, 23, 24, 2, 0] # 

def shellSort(Arr):

    n = len(Arr)
    interval =  n//2

    while interval>0:
        i=interval
        while i<n:

            if Arr[i-interval]>Arr[i]:
                Arr[i-interval], Arr[i] = Arr[i], Arr[i-interval]
            
            i+= 1
        
        interval //= 2

print(Array)
shellSort(Array) # shellSort Invoked
print(Array)
