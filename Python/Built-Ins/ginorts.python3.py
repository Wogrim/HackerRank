"""sort string grouped by lowercase, uppercase, odd, even"""

#filter to different groups and sort separately
s = input()
l=[x for x in s if x.islower()]
u=[x for x in s if x.isupper()]
o=[x for x in s if x.isdigit() and int(x)%2==1]
e=[x for x in s if x.isdigit() and int(x)%2==0]

print(*sorted(l),*sorted(u),*sorted(o),*sorted(e),sep='')


#alternative: sort with tuple key, note False sorts before True
s = input()
print(*sorted(s,key=lambda x:(not x.islower(),not x.isupper(),
                              not (x.isdigit() and int(x)%2==1), x)),sep='')


#alternative: create separate sort fuction to use as key
s = input()
def crazy_sort(x):
    #lowercase sorting value 0-25
    if x.islower():
        return ord(x)-ord('a')
    #uppercase sorting value 100-125
    elif x.isupper():
        return 100+ord(x)-ord('A')
    #odd digits sorting value 201-209
    elif int(x)%2==1:
        return 200+int(x)
    #even digits sorting value 300-308
    else:
        return 300+int(x)

print(*sorted(s,key=crazy_sort),sep='')