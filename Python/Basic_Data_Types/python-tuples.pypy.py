"""tuples immutable, can be hashed aka used as set/dictionary keys"""

if __name__ == '__main__':
    n = int(input())
    integer_list = map(int, input().split())
    
    t = tuple(integer_list)
    
    #apparently the hash in pypy is different from python3
    print(hash(t))
