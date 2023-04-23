"""slice a string to change a letter (or change to list)"""

def mutate_string(string, position, character):
    return string[:position]+character+string[position+1:]
