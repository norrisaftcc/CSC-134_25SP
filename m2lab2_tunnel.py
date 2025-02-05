# m2lab_snake.py
# csc 134
# norrisa
# 2/5/2025

from turtle import *

# setup
screen = Screen()
screen.bgcolor("black")
t = Turtle()
t.shape("turtle")
# apple
t.penup()
t.goto(-300, 300)
t.pendown()
t.pensize(5)
t.pencolor("red1")
t.fillcolor("red4")
t.begin_fill()
t.circle(30)
t.end_fill()

# draw the leaf

t.penup()
t.goto(-300, 300)
t.left(90)
t.forward(60)
t.pendown()

t.right(45)
t.pencolor("seagreen1")
t.forward(30)


# four snake heads
for direction in range(1):
    
    # Draw snake head
    t.penup()
    t.goto(0,0)
    t.pendown()
    t.right(90 * direction)
    t.left(45)
    t.fillcolor("seagreen4")
    t.begin_fill()
    for sides in (1,2,3):
        t.forward(40)
        t.right(120)
    t.end_fill()
    # tongue
    t.right(60)
    t.forward(40)
    t.right(30)
    t.pencolor("pink")
    t.forward(15)

    t.penup()
    t.forward(100)
    



