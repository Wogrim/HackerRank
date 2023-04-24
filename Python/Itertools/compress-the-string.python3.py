"""break an iterable into groups of repeated items"""

from itertools import groupby

s = map(int,list(input()))
for k, group in groupby(s):
    t = (len(list(group)),k)
    print(t,end=' ')

