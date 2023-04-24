"""defaultdict makes it convenient to have collection values"""

from collections import defaultdict

n, m = map(int,input().split())

a = defaultdict(list)

for i in range(n):
    word = input()
    a[word].append(i+1)

for _ in range(m):
    word = input()
    if word not in a:
        print(-1)
    else:
        print(*a[word])
