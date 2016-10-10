import sys

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

surfaceN = int(input()) # the number of points used to draw the surface of Mars.
for i in range(surfaceN):
    # landX: X coordinate of a surface point. (0 to 6999)
    # landY: Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
    landX, landY = [int(j) for j in input().split()]

prev_error = 0
sum_error = 0
TARGET_SPEED = -40.0

# PID controller constants
KP = 49
KI = 1
KD = 49

# game loop
while 1:
    # hSpeed: the horizontal speed (in m/s), can be negative.
    # vSpeed: the vertical speed (in m/s), can be negative.
    # fuel: the quantity of remaining fuel in liters.
    # rotate: the rotation angle in degrees (-90 to 90).
    # power: the thrust power (0 to 4).
    X, Y, HS, VS, F, R, P = [int(i) for i in input().split()]
    
    # PID controller
    error = TARGET_SPEED - VS
    sum_error += error
    prev_error = error
    cmd = KP * error + KI * sum_error + KD * (error - prev_error)

    power = int(min(max(cmd, 0), 4))
    print(0, power)
