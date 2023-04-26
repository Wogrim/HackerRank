"""iterator pass through an xml ElementTree"""

from xml.etree import ElementTree as etree

def get_attr_number(node: etree.Element) -> int:
    count = 0
    # iterate through the tree from the given node
    for n in node.iter():
        count += len(n.items())
    return count


#################################################

# get the xml into a string first (there's other ways also)
xml = "<stuff type='5'/>"
# then read it into a tree
tree = etree.ElementTree(etree.fromstring(xml))
# get the total number of attributes in the tree
print(get_attr_number(tree.getroot()))
