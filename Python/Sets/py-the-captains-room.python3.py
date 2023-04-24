"""finding the number that only shows up once in the list"""

k = int(input())
rooms = list(map(int,input().split()))
rooms_set = set(rooms)
print((k*sum(rooms_set)-sum(rooms))//(k-1))
