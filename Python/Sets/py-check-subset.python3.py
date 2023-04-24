"""check if all elements are in other set"""

t = int(input())
for _ in range(t):
    an, a = int(input()),set(input().split())
    bn, b = int(input()),set(input().split())
    print(a<=b)
