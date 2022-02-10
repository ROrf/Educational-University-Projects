import random
from turtle import Turtle

def recursive_drawing(turtle, angle, length, delta):
    colors = ["red", "orange", "yellow", "green", "blue", "purple", "pink", "magenta", "cyan", "teal", "maroon", "brown"]
    side = random.uniform(0, 1)
    direction = random.uniform(0, 1)
    turtle.color(random.choice(colors))
    if(side == 0):
        turtle.right(angle)
    else:
        turtle.left(angle)
    if(direction == 0):
        turtle.forward(length)
    else:
        turtle.backward(length)
    length = length - delta
    angle_change = random.uniform(1, 20)
    angle = angle + angle_change
    if(length > 1):
        recursive_drawing(turtle, angle, length, delta)

def main():
    random.seed()
    ANIMATION_SPEED = 0
    michelangelo = Turtle()
    michelangelo.speed(ANIMATION_SPEED)
    recursive_drawing(michelangelo, 0, 150, 1)

main()
