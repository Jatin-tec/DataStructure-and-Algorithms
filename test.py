#User function Template for python3
# class Solution:
    
#     def Partition(self, Arr, Lb, Ub):
#         #initializing pivot 
#         pivot = Arr[Lb]
    
#         #variable to find values bigger than pivot
#         bigger = Lb + 1
        
#         #variable to find values smaller than pivot
#         smaller = Ub
    
#         #this will go until all the smaller values are in left and bigger ones are right wrt pivot
#         while(bigger<smaller):
            
#             #searching for a value bigger than pivot 
#             #incrementing until we find one
#             while(Arr[bigger]<pivot):
#                 bigger += 1
            
#             #searching for a value smaller than pivot 
#             #decrementing until we find one
#             while(Arr[smaller]>pivot):
#                 smaller -= 1    
    
#             # to check if smaller and bigger value are in place
#             # smaller must be in left and vice versa 
#             if(smaller>bigger):
#                 Arr[bigger], Arr[smaller] = Arr[smaller], Arr[bigger]
        
#         #swapping current value of smaller with pivot
#         #as current value of smaller is the last value smaller than pivot and replacing it will get pivot in place 
#         Arr[smaller], Arr[Lb] = Arr[Lb], Arr[smaller]
    
#         #returning the index of sorted element
#         return smaller
    

#     def QuickSort(self, Arr, Lb, Ub):
    
#         if Lb<Ub:
            
#             #invoking Partition, it will take first element of given Array as piviot and place it in its position in sorted array
#             sortedIndex = self.Partition(Arr, Lb, Ub) 
            
#             # applying same in left sub Array of sorted element
#             self.QuickSort(Arr, Lb, sortedIndex-1) 
            
#             # applying same in right sub Array of sorted element
#             self.QuickSort(Arr, sortedIndex+1, Ub)

    
#     def matchPairs(self, nuts, bolts, n):
#         self.QuickSort(nuts, 0, n-1)
#         self.QuickSort(bolts, 0, n-1)

# solution=Solution()
# nuts=['@', '%', '$', '#', '^']
# bolts=['%', '@', "#", '$', '^'] 
# n=len(nuts)
# solution.matchPairs(nuts, bolts, n)
# print(bolts)
# print(nuts)

for i in range(5, 0, -1):
    print(i)

# for i in range(1, 3):
#     print(i)