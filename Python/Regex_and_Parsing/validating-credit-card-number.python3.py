"""credit card number validation"""

import re

# hyphen-separated groups of 4 digits
hyphen_pattern = re.compile(r"([0-9]{4}-){3}[0-9]{4}$")
# starts with 4/5/6 followed by 15 more digits (length and no other characters)
digits_pattern = re.compile(r"[4-6][0-9]{15}$")
# (no) quad-repeats
quad_repeat_pattern = re.compile(r"([0-9])\1{3}")

for _ in range(int(input())):
    string = input()
    if hyphen_pattern.match(string):
        string = string.replace('-','')
    if digits_pattern.match(string) and not quad_repeat_pattern.search(string):
        print("Valid")
    else:
        print("Invalid")
