"""maximizing a combination of items from different iterables"""

import itertools

k, m = map(int,input().split())
lists = []
for _ in range(k):
    #first number is the count, ignored
    a_list = map(int,input().split()[1:])
    lists.append([x**2 for x in a_list])
#actual best will always be >= 0 so we can start at zero
best = 0
for combo in itertools.product(*lists):
    best = max(best,sum(combo)%m)
print(best)
