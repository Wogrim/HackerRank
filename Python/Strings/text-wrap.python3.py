"""can break a string into multiple lines with textwrap"""

import textwrap

def wrap(string, max_width):
    broken_up_string = textwrap.fill(string, max_width)
    return broken_up_string
