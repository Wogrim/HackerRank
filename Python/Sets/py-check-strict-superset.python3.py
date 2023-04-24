"""checking if first set is strict superset of all others"""

is_superset=[]
a = set(input().split())
n = int(input())
for _ in range(n):
    b = set(input().split())
    is_superset.append(a>b)
print(all(is_superset))
