"""eval() to treat a string like code"""

#input 2 integers
x, k = map(int,input().split())
#input some expression that uses x
p = input()
#check if p with current x value evaluates to be equal to k
print(eval(p)==k)
