Array = [3, 1, 9, 7, 3, 1, 5, 6, 2]

def countSort(Arr):
    count = {}

    for key in Arr:
        if key not in count.keys():
            count[key] = 1  
        else:
            count[key] += 1

    # print(count)
    index=0        
    for i in range(10):
        if index<len(Arr):
            if i in count.keys():
                for j in range(count[i]):
                    Arr[index]=i
                    index += 1
        else:
            break
print('Before sort')
print(Array)  

countSort(Array)

print('After sort')
print(Array)  