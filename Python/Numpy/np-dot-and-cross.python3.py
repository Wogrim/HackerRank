"""matrix dot product and cross product"""

# numpy must be installed first
import numpy

n = int(input())
a = []
for _ in range(n):
    a.append(input().split())
narr_a = numpy.array(a,int)

b = []
for _ in range(n):
    b.append(input().split())
narr_b = numpy.array(b,int)

print(numpy.dot(narr_a,narr_b))
# numpy.cross() also available

