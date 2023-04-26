"""numpy.eye() makes a matrix full of zeros except 1 diagonal"""

# numpy must be installed first
import numpy
# something to match HackerRank test case format
numpy.set_printoptions(legacy='1.13')

n,m = map(int,input().split())
print(numpy.eye(n,m))
