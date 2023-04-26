"""filter() filters out elements that don't meet the condition"""

import re

# raw string to not have to escape the backslash
user_pat = r"[a-zA-Z0-9_\-]+"
site_pat = "[a-zA-Z0-9]+"
extn_pat = "[a-zA-Z]{1,3}"

def fun(s):
    if re.match(user_pat+"@"+site_pat+r"\."+extn_pat+"$",s):
        return True
    return False

# # to filter out non-emails from a list of emails
# print(list(filter(fun,list_of_emails)))