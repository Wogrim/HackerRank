"""split string into blocks, remove duplicates"""

def merge_the_tools(string, k):
    for i in range(0,len(string),k):
        u = []
        for j in range(i,i+k):
            if not string[j] in u:
                u.append(string[j])
        print(*u,sep='')

