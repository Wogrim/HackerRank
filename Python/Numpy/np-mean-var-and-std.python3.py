"""can reduce an array with mean, var, std on 1 or all dimensions"""

# numpy must be installed first
import numpy

n,m = map(int,input().split())
a = []
for _ in range(n):
    a.append(input().split())
narr_a = numpy.array(a,int)

print(numpy.mean(narr_a,axis=1))
print(numpy.var(narr_a,axis=0))
# round to proper precision to meet test case expectations
print(numpy.around(numpy.std(narr_a),11))
