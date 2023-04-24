"""put things in a set 1 at a time"""

n = int(input())
names = set()
for _ in range(n):
    names.add(input())
print(len(names))
