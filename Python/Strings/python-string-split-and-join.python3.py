"""split a string into a list, join list to string"""

def split_and_join(line):
    #basically replace spaces with hyphens
    return '-'.join(line.split(' '))

