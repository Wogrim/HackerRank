"""Match.start() and .end() give indices of the match"""

import re

s = input()
pattern = input()

result = re.search(pattern,s)
if result == None:
    print("(-1, -1)")
else:
    offset = 0
    while result != None:
        # start and end of the match
        print((result.start()+offset,result.end()+offset-1))
        # search again starting at 1 further character (allows overlap)
        offset += result.start()+1
        result = re.search(pattern,s[offset:])
