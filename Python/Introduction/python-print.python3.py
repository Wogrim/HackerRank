"""Print from 1 to input number without spaces."""

if __name__ == '__main__':
    n = int(input())
    for i in range(1,n+1):
        print(i,end='')

# if __name__ == '__main__':
#     n = int(input())
#     print(*range(1,n+1), sep='')