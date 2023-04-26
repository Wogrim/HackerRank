"""polynomial stuff can be done with array as coefficients"""

# numpy must be installed first
import numpy

poly = list(map(float,input().split()))
x = float(input())
# polyval just calculates the value at 
print(numpy.polyval(poly,x))


