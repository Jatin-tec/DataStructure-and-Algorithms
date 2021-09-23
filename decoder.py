Alpa = ['', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']

Array = [1, 2, 2] #  ADB, NB
Pair = []

i=0
for i in range(len(Array)-1):
    num = int(str(Array[i])+str(Array[i+1]))  
    Combo = []  
    
    j=0
    while j < len(Array):
        if j != i and j != i+1:
            Combo.append(Array[j])    
            j += 1
        else:
            Combo.append(num)
            j += 2
        if Combo not in Pair:    
            Pair.append(Combo)

double = []

i=0
while i < len(Array)-1:
    pairs = int(str(Array[i])+str(Array[i+1]))
    double.append(pairs)
    i += 2     
    
print(Pair)
print(double)

