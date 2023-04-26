"""regex pattern for roman numerals up to 3999"""

import re

# 0-3000
p_1000 = r"M{,3}"
# 400 or 900 or 500? + 0-300
p_100 = r"(CD|CM|D?(C){,3})"
# 40 or 90 or 50? + 0-30
p_10 = r"(XL|XC|L?(X){,3})"
# 4 or 9 or 5? + 0-3
p_1 = r"(IV|IX|V?(I){,3})"

regex_pattern = '^'+p_1000+p_100+p_10+p_1+'$'
