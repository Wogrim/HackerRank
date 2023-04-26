"""round the elements of a float numpy array"""

# numpy must be installed first
import numpy
# something to match HackerRank test case format
numpy.set_printoptions(legacy='1.13')

a = list(map(float,input().split()))
narr_a = numpy.array(a)

print(numpy.floor(narr_a))
print(numpy.ceil(narr_a))
print(numpy.rint(narr_a))
