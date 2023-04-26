"""re.findall() makes a list of all non-overlapping matches"""

import re

re_vowel = "[aeiouAEIOU]"
re_consonant = "[bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ]"

# 2 or more vowels with a consonant before and after
re_pattern = "(?<={0}){1}{1}+(?={0})".format(re_consonant,re_vowel)

patterns = re.findall(re_pattern,input())
if len(patterns)==0:
    print(-1)
else:
    print(*patterns,sep='\n')

# re.finditer() is similar but makes an iterator of MatchObjects
