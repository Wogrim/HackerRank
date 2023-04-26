"""NumPy lets you change array dimensions"""

#numpy must be installed first
import numpy

arr = list(map(int,input().split()))
narr = numpy.array(arr)
# change to 3x3 matrix
narr.shape = (3,3)
print(narr)
