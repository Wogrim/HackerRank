"""Counter is very convenient dict subclass"""

from collections import Counter

x = int(input())
sizes = map(int,input().split())
counts = Counter(sizes)
n = int(input())
money = 0
for _ in range(n):
    size, cost = map(int,input().split())
    if counts[size] > 0:
        money += cost
        counts[size] -= 1
print(money)
