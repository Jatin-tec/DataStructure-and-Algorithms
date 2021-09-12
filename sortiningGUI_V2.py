import turtle
from turtle import *

draw = turtle.Turtle()
screen = Screen()
screen.screensize(1600, 900)

# f = open('ArrayValues.txt', 'r')
# Array = list(f.read().split(','))

# for index in range(len(Array)):
#     Array[index] = int(Array[index])

Array = [31, 34, 23, 19, 10, 41, 8, 44, 16, 33, 39, 5, 30, 45, 12, 7, 25, 40, 3, 15, 38, 37, 21, 22, 13, 20, 32, 43, 49, 36, 47, 1, 24, 18, 28, 48, 42, 46, 0, 17, 2, 9, 29, 11, 14, 6, 35, 4, 26, 27]

def bubbleSort(Arr, draw):
    # initial Array
    dis=0
    for element in Arr:
        createLine(draw, -350+(dis*10), -250, element)
        dis += 1

    for i in range(len(Arr)-1):
        for j in range(len(Arr)-1-i):
            if Arr[j]>Arr[j+1]:
                Arr[j], Arr[j+1] = Arr[j+1], Arr[j] 
                createLine(draw, -350+(j*10), -250, Arr[j])
                createLine(draw, -350+((j+1)*10), -250, (Arr[j+1]))

def QuickSort(Arr, draw, Lb, Ub):

    if Lb<Ub:
        
        #invoking Partition, it will take first element of given Array as piviot and place it in its position in sorted array
        sortedIndex = Partition(Arr, draw, Lb, Ub) 
        
        # applying same in left sub Array of sorted element
        QuickSort(Arr, draw, Lb, sortedIndex-1) 
        
        # applying same in right sub Array of sorted element
        QuickSort(Arr, draw, sortedIndex+1, Ub)

def Partition(Arr, size, Lb, Ub):
    #initializing pivot 
    pivot = Arr[Lb]
    redLine(draw, -350+(Lb*10), -250, pivot)

    #variable to find values bigger than pivot
    bigger = Lb + 1
    
    #variable to find values smaller than pivot
    smaller = Ub

    #this will go until all the smaller values are in left and bigger ones are right wrt pivot
    while(bigger<smaller):
        
        #searching for a value bigger than pivot 
        #incrementing until we find one
        while(Arr[bigger]<=pivot):
            bigger += 1
        
        #searching for a value smaller than pivot 
        #decrementing until we find one
        while(Arr[smaller]>pivot):
            smaller -= 1    

        # to check if smaller and bigger value are in place
        # smaller must be in left and vice versa 
        if(smaller>bigger):
            Arr[bigger], Arr[smaller] = Arr[smaller], Arr[bigger]
            createLine(draw, -350+(smaller*10), -250, Arr[smaller])
            createLine(draw, -350+(bigger*10), -250, Arr[bigger])

    #swapping current value of smaller with pivot
    #as current value of smaller is the last value smaller than pivot and replacing it will get pivot in place 
    Arr[smaller], Arr[Lb] = Arr[Lb], Arr[smaller]
    createLine(draw, -350+(smaller*10), -250, Arr[smaller])
    createLine(draw, -350+(Lb*10), -250, Arr[Lb])

    #returning the index of sorted element
    greenLine(draw, -350+(smaller*10), -250, Arr[smaller])
    return smaller

Max=100

def greenLine(draw, xstr, ystr, yend):
    draw.penup()
    draw.goto(xstr, ystr)
    draw.pendown()
    draw.pencolor('white')
    draw.goto(xstr, Max)

    draw.penup()
    draw.goto(xstr, ystr)
    draw.pendown()
    draw.pencolor('green')
    draw.goto(xstr, ystr+yend)

def redLine(draw, xstr, ystr, yend):
    draw.penup()
    draw.goto(xstr, ystr)
    draw.pendown()
    draw.pencolor('white')
    draw.goto(xstr, Max)

    draw.penup()
    draw.goto(xstr, ystr)
    draw.pendown()
    draw.pencolor('red')
    draw.goto(xstr, ystr+yend)

def createLine(draw, xstr, ystr, yend):

    draw.penup()
    draw.goto(xstr, ystr)
    draw.pendown()
    draw.pencolor('white')
    draw.goto(xstr, Max)

    draw.penup()
    draw.goto(xstr, ystr)
    draw.pendown()
    draw.pencolor('black')
    draw.goto(xstr, ystr+yend)
        

draw.left(90)    
draw.width(5)
draw.speed(0)
dis=0
for element in Array:
    createLine(draw, -350+(dis*10), -250, element)
    dis += 1
QuickSort(Array, draw, 0, len(Array)-1)  

turtle.done()




# print(Array)
