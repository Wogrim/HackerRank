"""creating a list based on a formula"""

if __name__ == '__main__':
    x = int(input())
    y = int(input())
    z = int(input())
    n = int(input())

    #each item in the list is a list; [a,b,c]
    stuff = [[a,b,c] 
             #all combinations of a, b, and c from these ranges
             for a in range(x+1) 
             for b in range(y+1) 
             for c in range(z+1) 
             #but filter out combinations where a+b+c==n
             if a+b+c != n]
    
    print(stuff)
    