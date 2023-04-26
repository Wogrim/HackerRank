"""6 digit postal code regex checks (fictional?)"""

# 100000 to 999999
regex_integer_in_range = r"^[1-9]\d{5}$"
# a digit, another digit, then the first digit repeated
regex_alternating_repetitive_digit_pair = r"([0-9])(?=[0-9]\1)"
