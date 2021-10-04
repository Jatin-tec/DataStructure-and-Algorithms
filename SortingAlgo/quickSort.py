Array = [100, 3, 42, 1, 3123, 212]

def QuickSort(Arr, Lb, Ub):

    if Lb<=Ub:
        
        #invoking Partition, it will take first element of given Array as piviot and place it in its position in sorted array
        sortedIndex = Partition(Arr, Lb, Ub) 
        
        # applying same in left sub Array of sorted element
        QuickSort(Arr, Lb, sortedIndex-1) 
        
        # applying same in right sub Array of sorted element
        QuickSort(Arr, sortedIndex+1, Ub)

def Partition(Arr, Lb, Ub):
    #initializing pivot 
    pivot = Arr[Lb]

    #variable to find values bigger than pivot
    bigger = Lb + 1
    
    #variable to find values smaller than pivot
    smaller = Ub

    #this will go until all the smaller values are in left and bigger ones are right wrt pivot
    while(bigger<smaller):
        
        #searching for a value bigger than pivot 
        #incrementing until we find one
        print(bigger)
        while(Arr[bigger]<=pivot):
            bigger += 1
        
        #searching for a value smaller than pivot 
        #decrementing until we find one
        print(smaller)
        while(Arr[smaller]>=pivot):
            smaller -= 1    

        # to check if smaller and bigger value are in place
        # smaller must be in left and vice versa 
        if(bigger<smaller):
            Arr[bigger], Arr[smaller] = Arr[smaller], Arr[bigger]
    
    #swapping current value of smaller with pivot
    #as current value of smaller is the last value smaller than pivot and replacing it will get pivot in place 
    Arr[smaller], Arr[Lb] = Arr[Lb], Arr[smaller]

    #returning the index of sorted element
    return smaller

print('Array before sort')
print(Array)

QuickSort(Array, 0, (len(Array)-1))    

print('Array after sort')
print(Array)
