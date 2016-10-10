import sys
import math

l = int(input())
h = int(input())
t = input()
row = [input() for i in range(h)]

for j in range(h):
    for i in t:
        asc=(ord(i.upper())-65) if i.isalpha() else 26
        print(row[j][(l*asc):(l*(asc+1))],end='')
    print()
