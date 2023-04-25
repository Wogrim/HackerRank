"""tests if input is a valid regular expression"""

import re

t = int(input())
for _ in range(t):
    s = input()
    try:
        re.compile(s)
        print(True)
    except Exception as e:
        print(False)
        
