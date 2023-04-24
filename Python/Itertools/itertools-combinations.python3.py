"""all i-length combinations of items in iterable S"""

from itertools import combinations

inp = input().split()
S = sorted(inp[0])
k = int(inp[1])
for i in range(1,k+1):
    for t in combinations(S,i):
        print(''.join(t))
