"""3 most-common characters in a string, alphabetical ties"""

from collections import Counter

if __name__ == '__main__':
    s = input()
    counts = Counter(s)
    by_letter = sorted(counts.items())
    by_count = sorted(by_letter,key=lambda x:x[1],reverse=True)
    for i in range(3):
        print(*by_count[i])
    

# Counter lets you get the n most common, but unreliable with ties
top3 = counts.most_common(3)
# itemgetter() is an easy way to grab a certain field to sort by
from operator import itemgetter
by_letter = sorted(top3,key=itemgetter(0))
by_count = sorted(by_letter,key=itemgetter(1),reverse=True)

