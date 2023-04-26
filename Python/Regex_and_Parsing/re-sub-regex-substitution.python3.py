"""re.sub() replaces matches with return value of a function"""

import re

# find && or || with space on both sides
regex = r"(?<= )(&&|[|]{2})(?= )"

def and_or(match):
    if(match.group(0)=="&&"):
        return "and"
    else:
        return "or"
    
for _ in range(int(input())):
    line = input()
    print(re.sub(regex,and_or,line))

