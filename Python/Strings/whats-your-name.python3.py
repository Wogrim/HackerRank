"""multiple ways to put variable in a string"""

def print_full_name(first, last):
    #simple concatenation
    print("Hello "+first+" "+last+"! You just delved into python.")

def print_full_name2(first, last):
    #f-string
    print(f"Hello {first} {last}! You just delved into python.")

def print_full_name3(first, last):
    #string.format()
    print("Hello {0} {1}! You just delved into python.".format(first, last))
    