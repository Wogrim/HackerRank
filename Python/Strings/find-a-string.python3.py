"""counting how many times a substring appears"""

def count_substring(string, sub_string):
    count = 0
    sl = len(string)
    ssl = len(sub_string)
    for i in range(sl-ssl+1):
        if string[i:i+ssl] == sub_string:
            count += 1
    
    return count
