"""more dumb ascii art, with increasing letters"""

import string

def print_rangoli(size):
    lines = []
    width = (size*2-1)*2-1
    # create lower half
    for i in range(size):
        line = []
        # left side letters
        for j in range(size-1,i,-1):
            line.append(string.ascii_lowercase[j])
        # center letter
        line.append(string.ascii_lowercase[i])
        # right side letters
        for j in range(i+1,size):
            line.append(string.ascii_lowercase[j])
        # add to lines
        lines.append(line)
    # print upper half (not including middle)
    for line in lines[size-1:0:-1]:
        print('-'.join(line).center(width,'-'))
    # print lower half
    for line in lines:
        print('-'.join(line).center(width,'-'))
        
# can grab letters from string.ascii_lowercase
# or chr(num) converts the num to a 1-character string
