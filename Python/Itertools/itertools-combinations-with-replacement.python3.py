"""basically combinations but allows multiple of same element"""

from itertools import combinations_with_replacement

S, K = input().split()

for c in combinations_with_replacement(sorted(S),int(K)):
    print(''.join(c))
