import turtle
def show_design(width):
    for i in range(4):
        turtle.penup()
        turtle.goto(i*5, i*5)
        turtle.pendown()

        turtle.forward(width-i*5*2)
        turtle.left(90)
        turtle.forward(width-i*5*2)
        turtle.left(90)
        turtle.forward(width-i*5*2)
        turtle.left(90)
        turtle.forward(width-i*5*2)
        turtle.left(90)

    turtle.hideturtle()
    turtle.done()
    
    
def main():
    show_design(100)
    
main()


