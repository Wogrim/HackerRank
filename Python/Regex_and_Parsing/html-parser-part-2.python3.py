"""you can make a HTMLParser that does things when parsing HTML"""

from html.parser import HTMLParser

class MyHTMLParser(HTMLParser):
    def handle_comment(self, data):
        if str.find(data,'\n') == -1:
            print(">>> Single-line Comment")
        else:
            print(">>> Multi-line Comment")
        print(data)
    def handle_data(self, data):
        if data=='\n':
            return
        print(">>> Data")
        print(data)
  
  
html = ""       
for i in range(int(input())):
    html += input().rstrip()
    html += '\n'
    
parser = MyHTMLParser()
parser.feed(html)
parser.close()
