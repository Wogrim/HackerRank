"""cartesian product is all combos of tuples from 2 iterables"""

import itertools

a,b = map(int,input().split()), map(int,input().split())
print(*itertools.product(a,b))
