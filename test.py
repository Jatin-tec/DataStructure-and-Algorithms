import turtle as t
import time as te

wn = t.Screen()
wn.title('paint app with python')
wn.bgcolor('white')
wn.setup(height=600, width=600)

obj= t.Turtle()
obj.shape('square')
obj.color('black')
obj.pendown()

menu=t.Turtle()
menu.penup()
menu.goto(0,250)

# menu.write('blue-B','green-G','red-R')






def move_up():
    y=obj.ycor()
    y+=20
    obj.sety(y)

def move_down():
    y=obj.ycor()
    y-=20
    obj.sety(y)

def move_right():
    x=obj.ycor()
    x+=20
    obj.setx(x)

def move_left():
    x=obj.ycor()
    x-=20
    obj.setx(x)  


def blue():
    obj.pencolor('blue')
    obj.pendown() 

def red():
    obj.pencolor('red')
    obj.pendown()          

def green():
    obj.pencolor('green')
    obj.pendown()

wn.listen()
wn.onkeypress(move_up,'up')
wn.onkeypress(move_down,'down')
wn.onkeypress(move_right,'right')
wn.onkeypress(move_left,'left') 
wn.onkeypress(blue,'b') 
wn.onkeypress(red,'r')     
wn.onkeypress(green,'g') 

t.done()