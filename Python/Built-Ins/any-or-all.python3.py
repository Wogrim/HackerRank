"""all(iterable) and any(iterable) give boolean"""

n = int(input())
snumbers = input().split()
if (all(int(x)>0 for x in snumbers)
        and any(x==x[::-1] for x in snumbers)):
    print(True)
else:
    print(False)
