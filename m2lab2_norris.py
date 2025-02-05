# M2LAB2 - graphics
# norrisa
# 2/5/2025
# Goal: Learn some simple graphics tools.

from turtle import *

screen = Screen()
screen.bgcolor("black")

t = Turtle()
# change the color and size to whatever you want
t.pencolor("bisque1")
t.pensize(5)
t.shape("turtle")


# happy little house
# This is a loop
t.fillcolor("bisque3")
t.begin_fill()
for side in range(4):
    t.forward(100)
    t.right(90)
t.end_fill()

# put the roof on the house
for side in range(3):
    t.forward(100)
    t.left(120)

# something different
# moving around
t.penup()
t.forward(300)
t.pendown()
for mycolor in ("aquamarine","darkgoldenrod","darkkhaki"):
    t.color(mycolor)
    t.forward(100)
    t.right(120)

t.color("indianred1")
# worlds slowest circle
for side in range(36):
    t.forward(10)
    t.left(10)

t.circle(100, 180) # 180 degrees is half of a circle
