"""OrderedDict keeps track of the order keys are entered in"""

from collections import OrderedDict

o_dict = OrderedDict()
n = int(input())
for _ in range(n):
    name, price = input().rsplit(' ',1)
    if name in o_dict:
        o_dict[name]+= int(price)
    else:
        o_dict[name]= int(price)
for name, price in o_dict.items():
    print(name,price)
    
