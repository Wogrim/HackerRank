"""some regex replacement"""

import re

# select non-alnum characters between alnum characters
replace_pattern = re.compile(r"(?<=[a-zA-Z0-9])[^a-zA-Z0-9]+(?=[a-zA-Z0-9])")

n, m = map(int,input().split())

# matrix is a list of rows
matrix = []
for _ in range(n):
    matrix_item = input()
    matrix.append(matrix_item)

# convert matrix to properly-ordered string
string = "".join([matrix[j][i] for i in range(m) for j in range(n)])

# replace spaces, symbols, etc with a single space between words
print(replace_pattern.sub(" ",string))
