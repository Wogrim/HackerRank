"""some regex validation"""

import re

for _ in range(int(input())):
    inp = input()
    # at least 2 uppercase
    if len(re.findall("[A-Z]",inp)) < 2:
        print("Invalid")
    # at least 3 digits
    elif len(re.findall("\d",inp)) < 3:
        print("Invalid")
    # 10 alphanumeric characters
    elif re.match("[a-zA-Z0-9]{10}$",inp) == None:
        print("Invalid")
    # 10 length without repeated characters
    elif len(set(inp)) != 10:
        print("Invalid")
    else:
        print("Valid")
