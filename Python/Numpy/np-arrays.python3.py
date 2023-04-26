"""NumPy array is homogeneous"""

#numpy must be installed first
import numpy

def arrays(arr:list) -> numpy.ndarray:
    #reverse the original array and make it a numpy float array
    return numpy.array(arr[::-1],float)


##################################################

arr = input().strip().split(' ')
result = arrays(arr)
print(result)