"""concatenation of numpy arrays"""

#numpy must be installed first
import numpy

n,m,p = map(int, input().split())

arr1=[]
arr2=[]
for _ in range(n):
    arr1.append(list(map(int,input().split())))
for _ in range(m):
    arr2.append(list(map(int,input().split())))
narr1 = numpy.array(arr1)
narr2 = numpy.array(arr2)

#note the tuple
print(numpy.concatenate((narr1,narr2)))
