"""re.match() returns None if no match found"""

import re

# a floating point regular expression
re_float = r"[+-]?[0-9]*\.[0-9]+\Z"

for _ in range(int(input())):
    print(re.match(re_float,input())!=None)
