"""different formats for numbers, fixed width align right"""

def print_formatted(number):
    width = len(format(number,"b"))
    swidth = str(width)
    for n in range(1,number+1):
        decimal = format(n,">"+swidth)
        binary = format(n,">"+swidth+"b")
        nhex = format(n,">"+swidth+"X")
        octal = format(n,">"+swidth+"o")
        print(' '.join([decimal,octal,nhex,binary]))

#decimal
print(format(147,">8"))
print("{0:8d}".format(147))
#octal
print(format(147,">8o"))
print("{0:8o}".format(147))
#hex
print(format(147,">8X"))
print("{0:8X}".format(147))
#binary
print(format(147,">8b"))
print("{0:8b}".format(147))
