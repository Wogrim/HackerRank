"""different ways to remove items from a set"""

n = int(input())
s = set(map(int, input().split()))
q = int(input())
for _ in range(q):
    query = input().split()
    try:
        if query[0] == "pop":
            s.pop()
        elif query[0] == "remove":
            s.remove(int(query[1]))
        elif query[0] == "discard":
            s.discard(int(query[1]))
    except:
        pass
print(sum(s))
