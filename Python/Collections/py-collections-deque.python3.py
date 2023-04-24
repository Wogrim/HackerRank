"""deque can append, appendleft, pop, popleft"""

from collections import deque

d = deque()
n = int(input())
for _ in range(n):
    query = input().split()
    #running input strings as code via eval()
    if len(query) > 1:
        eval("d.{0}({1})".format(query[0],query[1]))
    else:
        eval("d.{0}()".format(query[0]))
print(*d)
