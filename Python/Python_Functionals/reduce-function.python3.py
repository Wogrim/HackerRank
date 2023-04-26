"""reduce() combines elements of an iterable down to a single value"""

from fractions import Fraction
from functools import reduce

# reduce a list of Fraction by multiplying them together
def product(fracs):
    t =  reduce(lambda cumulative,item:cumulative*item,fracs,1)
    return t.numerator, t.denominator

