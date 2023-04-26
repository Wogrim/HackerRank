"""match is None (falsey) if no match"""

import re

# 10 digit number starting with 7, 8, or 9
pattern = "^[7-9]\d{9}$"

for _ in range(int(input())):
    match = re.match(pattern,input())
    print("YES" if match else "NO")
