"""sort rows of input data by k-th column"""

n,m = map(int,input().split())
table = []
for _ in range(n):
    table.append(list(map(int, input().rstrip().split())))

k = int(input())
#sort by k-th element
table.sort(key=lambda x: x[k])
for row in table:
    print(*row)
