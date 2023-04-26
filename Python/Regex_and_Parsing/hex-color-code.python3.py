"""a 3-digit or 6-digit hex code following a space or colon"""

import re

pattern = re.compile(r"(?<=[: ])#(?:[a-fA-F0-9]{6}|[a-fA-F0-9]{3})\b")

for _ in range(int(input())):
    inp = input()
    result = pattern.findall(inp)
    if result != []:
        print(*result,sep='\n')

