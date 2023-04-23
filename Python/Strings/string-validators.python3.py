"""use of some simple built-in validators"""

if __name__ == '__main__':
    s = input()
    has_alnum = False
    has_alpha = False
    has_digit = False
    has_lower = False
    has_upper = False
    for c in s:
        if c.isdigit():
            has_digit = True
        if c.islower():
            has_lower = True
        if c.isupper():
            has_upper = True
    if has_lower or has_upper:
        has_alpha = True
    if has_alpha or has_digit:
        has_alnum = True
    print(has_alnum)
    print(has_alpha)
    print(has_digit)
    print(has_lower)
    print(has_upper)
