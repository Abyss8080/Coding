from turtle import *
def quare():
    forward(100)
    left(90)
    forward(50)
    left(90)
    forward(100)
    left(90)
    forward(50)
    left(90)

def main():
    quare()
    penup()
    goto(0,100)
    pendown()
    quare()
    hideturtle()

main()

