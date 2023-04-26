"""can reduce an array with min or max on 1 or all dimensions"""

# numpy must be installed first
import numpy

n,m = map(int,input().split())
a=[]
for _ in range(n):
    a.append(input().split())
narr_a = numpy.array(a,int)

mins = numpy.min(narr_a,axis=1)
print(numpy.max(mins))
