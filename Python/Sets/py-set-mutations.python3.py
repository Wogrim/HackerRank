"""changing the original set"""

n = int(input())
a = set(input().split())
n = int(input())
for _ in range(n):
    op_type, length = input().split()
    this_set = set(input().split())
    if op_type == "intersection_update":
        a &= this_set
    elif op_type == "difference_update":
        a -= this_set
    elif op_type == "symmetric_difference_update":
        a ^= this_set
    elif op_type == "update":
        a |= this_set
print(sum(map(int,a)))
