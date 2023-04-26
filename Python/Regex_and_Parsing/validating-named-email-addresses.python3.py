"""email.utils has some stuff for building emails"""

import re
import email.utils

username = r"[a-zA-Z][a-zA-Z0-9\-._]*"
domain = r"@[a-zA-Z]+"
extension = r"\.[a-zA-Z]{1,3}"

pattern = re.compile('^' + username + domain + extension + '$')

for _ in range(int(input())):
    name, address = email.utils.parseaddr(input())
    if pattern.match(address) != None:
        print(email.utils.formataddr((name,address)))
