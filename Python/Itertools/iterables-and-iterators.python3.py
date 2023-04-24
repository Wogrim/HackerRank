"""counting combinations that meet a condition"""

import itertools

n = int(input())
letters = input().split()
k = int(input())
count = 0
total = 0
for c in itertools.combinations(sorted(letters),k):
    if c[0]=='a':
        count +=1
    total += 1
print(count/total)
