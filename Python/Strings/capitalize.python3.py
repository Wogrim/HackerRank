"""capitalize first letter of each word only if starts with letter"""

def solve(s):
    separated =  s.split(' ')
    return ' '.join(word.capitalize() for word in separated)

