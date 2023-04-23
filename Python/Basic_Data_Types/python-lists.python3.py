"""basic list manipulation"""

if __name__ == '__main__':
    stuff = []
    N = int(input())
    
    for _ in range(N):
        fn, *args = input().split()
        args = list(map(int,args))
        if fn=="insert":
            stuff.insert(args[0],args[1])
        elif fn=="print":
            print(stuff)
        elif fn=="remove":
            stuff.remove(args[0])
        elif fn=="append":
            stuff.append(args[0])
        elif fn=="sort":
            stuff.sort()
        elif fn=="pop":
            #value not used
            stuff.pop()
        else:
            # "reverse"
            stuff.reverse()
