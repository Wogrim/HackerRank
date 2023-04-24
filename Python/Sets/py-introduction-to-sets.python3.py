"""build a set from an array to remove duplicates"""

def average(array):
    distnct = set(array)
    return sum(distnct)/len(distnct)
