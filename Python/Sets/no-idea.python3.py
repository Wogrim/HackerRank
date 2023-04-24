"""easy to check if value in a set"""

n, m = map(int,input().split())
arr = list(map(int,input().split()))
a = set(map(int,input().split()))
b = set(map(int,input().split()))
happiness = 0
for val in arr:
    if val in a:
        happiness += 1
    elif val in b:
        happiness -= 1
print(happiness)
