"""matrix inner product and outer product"""

# numpy must be installed first
import numpy

a = input().split()
b = input().split()
narr_a = numpy.array(a,int)
narr_b = numpy.array(b,int)

print(numpy.inner(narr_a,narr_b))
print(numpy.outer(narr_a,narr_b))

