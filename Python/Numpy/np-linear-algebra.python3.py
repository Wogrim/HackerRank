"""determinant, matrix inverse, eigenvalues and eigenvectors"""

# numpy must be installed first
import numpy

n = int(input())
a=[]
for _ in range(n):
    a.append(input().split())
narr_a = numpy.array(a,float)

# determinant (rounded to 2 decimal places)
print(numpy.around(numpy.linalg.det(narr_a),2))


##################################################

# inverse
print(numpy.linalg.inv(narr_a))

# eigenvalues and eigenvectors
eigenvalues, eigenvectors = numpy.linalg.eig(narr_a)
print(eigenvalues)
print(eigenvectors)
