"""recursive pass through an xml ElementTree"""

from xml.etree import ElementTree as etree

maxdepth = 0
def depth(elem: etree.Element, level: int):
    global maxdepth
    level += 1
    maxdepth = max(maxdepth,level)
    # recursively go through the children
    for child in elem:
        depth(child,level)


#################################################

# get the xml into a string first (there's other ways also)
xml = "<stuff type='5'/>"
# then read it into a tree
tree = etree.ElementTree(etree.fromstring(xml))
# calculate maxdepth by running the function
depth(tree.getroot(), -1)

print(maxdepth)
