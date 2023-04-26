"""numpy arrays can use math per-element"""

# numpy must be installed first
import numpy

n,m = map(int,input().split())
a=[]
b=[]
for _ in range(n):
    a.append(input().split())
for _ in range(n):
    b.append(input().split())

narr_a = numpy.array(a,int)
narr_b = numpy.array(b,int)

print(narr_a+narr_b)
print(narr_a-narr_b)
print(narr_a*narr_b)
print(narr_a//narr_b)
print(narr_a%narr_b)
print(narr_a**narr_b)
