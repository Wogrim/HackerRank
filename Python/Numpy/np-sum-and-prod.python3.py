"""can reduce an array with sum or product on 1 or all dimensions"""

# numpy must be installed first
import numpy

n,m = map(int,input().split())
a=[]
for _ in range(n):
    a.append(input().split())
narr_a = numpy.array(a,int)

narr_sum = numpy.sum(narr_a,axis=0)
narr_prod = numpy.prod(narr_sum)
print(narr_prod)
