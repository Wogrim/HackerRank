"""create a union of sets"""

n = int(input())
e = set(map(int,input().split()))
b = int(input())
f = set(map(int,input().split()))
print(len(e.union(f)))
