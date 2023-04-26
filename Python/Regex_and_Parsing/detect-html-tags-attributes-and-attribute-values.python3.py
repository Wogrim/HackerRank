"""you can make a HTMLParser that does things when parsing HTML"""

from html.parser import HTMLParser

class MyHTMLParser (HTMLParser):
    def handle_starttag(self, tag, attrs):
        print(tag)
        for attr in attrs:
            print("-> {0} > {1}".format(attr[0],attr[1]))

html_string = ""
for _ in range(int(input())):
    html_string += input()

parser = MyHTMLParser()
parser.feed(html_string)
parser.close

