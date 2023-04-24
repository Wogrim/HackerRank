"""Counter keeps track of insertion order"""

from collections import Counter

counts = Counter()
n = int(input())
for _ in range(n):
    counts[input()]+= 1
print(len(counts))
print(*counts.values())
    
