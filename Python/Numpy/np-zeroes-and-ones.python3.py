"""easy to make an array full of zeroes or ones"""

#numpy must be installed first
import numpy

#input dimensions of the array
sizes = tuple(map(int,input().split()))

#make such an array with all zeros
print(numpy.zeros(sizes,int))

#make such an array with all ones
print(numpy.ones(sizes,int))
