"""get all values in only 1 of 2 sets"""

m = int(input())
a = set(map(int,input().split()))
n = int(input())
b = set(map(int,input().split()))
sym_diff = a.symmetric_difference(b)
print(*sorted(sym_diff),sep='\n')
