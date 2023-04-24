"""all k-length permutations of iterable s (=> iterable of tuples)"""

from itertools import permutations

S, K = input().split()
k = int(K)
s = sorted(S)
for p in permutations(s,k):
    print("".join(p))

