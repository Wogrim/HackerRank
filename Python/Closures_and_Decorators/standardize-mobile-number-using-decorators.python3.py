"""decorate sort function to standardize format before sorting"""

def wrapper(f):
    def fun(l):
        #new list for standardized numbers
        newl=[]
        for num in l:
            start = len(num)-10
            newl.append("+91 "+num[start:start+5]+" "+num[start+5:])
        #call the original function with the standardized list
        f(newl)
    return fun


##################################################

@wrapper
def sort_phone(l):
    print(*sorted(l), sep='\n')

if __name__ == '__main__':
    l = [input() for _ in range(int(input()))]
    sort_phone(l)
