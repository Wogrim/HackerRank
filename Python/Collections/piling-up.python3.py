"""grab the larger element from the ends"""

from collections import deque

t = int(input())
for _ in range(t):
    possible = True
    n = int(input())
    d = deque(map(int,input().split()))
    base = max(d[0],d[-1])
    while len(d) > 0:
        if d[0] > d[-1]:
            newblock = d.popleft()
        else:
            newblock = d.pop()
        if newblock > base:
            possible = False
            break
        base = newblock
    if possible:
        print("Yes")
    else:
        print("No")
    