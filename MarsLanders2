import sys
import math
import numpy as np

def findLandingPoint( surf):
    prev_coords = [-1,-1]
    for coords in surf:
        print(coords, file=sys.stderr)
        if( coords[1] == prev_coords[1]):
            y = coords[1] 
            x = coords[0] + prev_coords[0]
            
            return x/2 ,y, abs(coords[0] - prev_coords[0])
        prev_coords = coords
    

class Ship:
    def __init__(self):
        surface_n = int(input())  # the number of points used to draw the surface of Mars.
        surface = []

        self.s = 0
        for i in range(surface_n):
            # land_x: X coordinate of a surface point. (0 to 6999)
            # land_y: Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
            x, y = [int(j) for j in input().split()]
            surface.append( [x, y] )          
            
        self.land_x, self.land_y, self.dx = findLandingPoint(surface)
            
        
    def controller(self):
        self.x, self.y, self.h_speed, self.VS, self.fuel, self.rotate, self.power = [int(i) for i in input().split()]
        
        if (self.s == 0):
            self.s = np.sign( self.x - self.land_x)         
        
        NRT = np.abs(self.h_speed / 4.0) + 4
        distX = np.abs(self.x - self.land_x) 
        distY = np.abs(self.y - self.land_y) 
        
        if np.abs(distY) < np.abs(distX) and self.VS < 0: 
            print( "Keeping up", file=sys.stderr)
            self.rotate = 0
            self.power = 4 
        elif np.abs(distX / self.h_speed) > NRT and distX > self.dx/2:
            print( "Moving to X", file=sys.stderr)
            self.s = np.sign( self.x - self.land_x) 
            self.rotate = np.sign( self.x - self.land_x) * 45
            self.power = 4
        elif np.abs(self.h_speed) > 10:
            print( "Reducing hs", file=sys.stderr)
            self.rotate = -self.s * 45
            self.power = 4
        else:
            print( "Reducing vs", file=sys.stderr)
            self.rotate = 0
            self.power = 4 
            
# game loop
s = Ship()
while True:
    # h_speed: the horizontal speed (in m/s), can be negative.
    # v_speed: the vertical speed (in m/s), can be negative.
    # fuel: the quantity of remaining fuel in liters.
    # rotate: the rotation angle in degrees (-90 to 90).
    # power: the thrust power (0 to 4).
    s.controller()    
    print(int(s.rotate), s.power)
