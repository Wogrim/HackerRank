"""NumPy has some convenient matrix functions"""

#numpy must be installed first
import numpy

n, m = map(int,input().split())

arr = []
for _ in range(n):
    arr.append(list(map(int,input().split())))
narr = numpy.array(arr)
# transpose
print(numpy.transpose(narr))
# flatten to single row
print(narr.flatten())
