"""handling exceptions with their error message"""

t = int(input())
for _ in range(t):
    a, b = input().split()
    try:
        print(int(a)//int(b))
    except ZeroDivisionError as e:
        print("Error Code:",e)
    except ValueError as e:
        #problem with int(a) or int(b)
        print("Error Code:",e)
        
