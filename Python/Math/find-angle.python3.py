"""formatting an angle calculated with arctangent"""

import math

a,b = int(input()),int(input())

# m is at (b/2,a/2)

angle = math.degrees(math.atan(a/b))
print("{0:.0f}".format(angle)+chr(176))
