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
t.pencolor("pink")
t.pensize(5)

sizes = [10, 20, 30, 40, 50, 100, 150, 200]
sides = [3, 4, 5, 6, 7, 8, 9, 10, 11]
colors= ["white","gray90","gray80","gray70","gray60","slategray1", "slategray2","slategray3"]
for times in range(8):
    t.penup()
    t.goto(-300,-300)
    t.pendown()
    # draw a polygon of size and side
    my_size = sizes[times]
    my_sides= sides[times]
    print("size=",my_size,"sides=",my_sides)
    t.pencolor(colors[times])

    for side in range(my_sides):
        t.forward(my_size)
        t.left(360/my_sides)
        


