"""use cmath to do things with complex numbers"""

import cmath

z = complex(input())

print(abs(z))
print(cmath.phase(z))

# or get these with cmath.polar()
