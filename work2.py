import turtle

def graph(x,y,color,e,angle):
    turtle.penup()
    turtle.goto(x,y)
    turtle.pendown()
    turtle.begin_fill()
    turtle.color(color)
    turtle.circle(e,steps=360//angle)
    turtle.end_fill()

def main():
    turtle.pensize(3)
    graph(-250,-50,"red",40,120)
    graph(-150,-50,"blue",40,90)
    graph(-50,-50,"green",40,72)
    graph(50,-50,"yellow",40,60)
    turtle.color("black")
    turtle.penup()
    turtle.goto(150,-50)
    turtle.pendown()
    turtle.begin_fill()
    turtle.color("green")
    turtle.circle(40,extent=270)
    turtle.left(90)
    turtle.forward(40)
    turtle.right(90)
    turtle.forward(40)
    turtle.end_fill()
    turtle.penup()
    turtle.goto(230,0)
    turtle.pendown()
    turtle.begin_fill()
    turtle.color("purple")
    turtle.circle(40)
    turtle.end_fill()
    
    turtle.color("red")
    turtle.penup()
    turtle.goto(-100,50)
    turtle.pendown()
    turtle.write("Cool Color Shapes",font=("Times",18,"bold"))
    turtle.hideturtle()

    turtle.done()

main()




