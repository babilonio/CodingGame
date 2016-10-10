import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

def getAsciiIndex(c):
    if ord(c) >= 65 and ord(c) <= 90:
        return ord(c) - 65
    elif ord(c) >= 97 and ord(c) <= 122:
        return ord(c) - 97
    else:
        return 26

l = int(input())
h = int(input())
t = input()

for c in t:
    print(c,end="", file=sys.stderr)
print("", file=sys.stderr)

for i in range(h):
    row = input()
    #print(row)
    for c in t:
        print( row[ getAsciiIndex(c)*l : getAsciiIndex(c)*l + l],end="")
    print("")
# Write an action using print
# To debug: print("Debug messages...", file=sys.stderr)
