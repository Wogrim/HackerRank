"""map() a function to an iterable to get an iterable"""

cube = lambda x: x*x*x 

def fibonacci(n):
    if n == 0:
        return []
    elif n == 1:
        return [0]
    fibs = [0,1]
    for i in range(2,n):
        fibs.append(fibs[i-2]+fibs[i-1])
    return fibs

# # get the cubes of the first 10 fibonacci numbers
# for f3 in map(cube,fibonacci(10)):
#     print(f3)