"""groups let you catch a repeated substring"""

import re

# the regex will find a letter or number that is immediately repeated
# the whole match is all the characters until it stops repeating
# group 1 is just the first character
expression = r"([a-zA-Z0-9])\1+"

result = re.search(expression,input())
if result == None:
    print(-1)
else:
    print(result.group(1))
