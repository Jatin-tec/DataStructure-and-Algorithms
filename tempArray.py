import random

Array = []

while len(Array)<50:
    number = random.randint(0, 50)
    if number not in Array:
        Array.append(number)

print(len(Array))        


