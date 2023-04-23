"""some list manipulation stuff"""

if __name__ == '__main__':
    n = int(input())
    #convert the input to a list of integers
    arr = map(int, input().split())
    #remove duplicates
    uniques = list(set(arr))
    #sort and get the second-largest
    uniques.sort()
    print(uniques[-2])

