// a big painful mess of parsing, dynamic allocation, and hashmaps

#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

class Tag
{
public:
    string tagname;
    unordered_map<string, string> attributes;
    unordered_map<string, Tag *> children;

    // constructors
    Tag(string tagname) : tagname(tagname) {}
    Tag() : tagname("DEFAULT") {}

    // deconstructor: delete child Tags
    ~Tag()
    {
        for (auto childPair : children)
            delete childPair.second;
    }

    // for debugging
    void printTag()
    {
        cout << "tag name <" << tagname << ">" << endl;
        cout << "attributes" << endl;
        for (auto attribute : attributes)
            cout << "    " << attribute.first << "=" << '"' << attribute.second << '"' << endl;
        cout << "children" << endl;
        for (auto child : children)
            cout << "    " << child.first << "=" << '"' << child.second->tagname << '"' << endl;
    }
};

int main()
{
    // read N and Q from the first line of input
    int n, q;
    cin >> n >> q;
    cin.ignore();

    // all the top-level tags
    unordered_map<string, Tag *> top_tags;

    // tag stack for nesting
    stack<Tag *> tag_stack;

    // read each line of input
    string line, temp;
    int position, end;
    for (int i = 0; i < n; i++)
    {
        getline(cin, line);

        position = 0;

        // opening bracket
        while (line[position] != '<')
            position++;
        position++;

        // check if closing tag (slash)
        if (line[position] == '/')
        {
            // pop from tag stack, done with this line because good format
            tag_stack.pop();
            continue;
        }

        // go through tag name until space or closing bracket
        for (end = position + 1; line[end] != ' ' && line[end] != '>'; end++)
            ;

        // create the tag with the tagname
        Tag *currentTag = new Tag(line.substr(position, end - position));

        // if space, read attribute
        while (line[end] == ' ')
        {
            position = end + 1;
            // attribute name until space
            for (end = position + 1; line[end] != ' '; end++)
                ;
            temp = line.substr(position, end - position);

            // skip past space, equals, space, quote
            position = end + 4;

            // attribute value until end quote
            for (end = position; line[end] != '"'; end++)
                ;

            // put the attribute on the tag
            currentTag->attributes[temp] = line.substr(position, end - position);

            // DEBUG
            //  cout << "attribute:" << temp << '=' << line.substr(position,end-position) << endl;

            // go past end quote for next iteration to see if another attribute
            end++;
        }
        // closing bracket, done with this line because good format

        // currentTag is a child of the top tag on the stack if it's not empty, else top-level
        if (tag_stack.empty())
            top_tags[currentTag->tagname] = currentTag;
        else
            tag_stack.top()->children[currentTag->tagname] = currentTag;

        // put currentTag on top of the stack
        tag_stack.push(currentTag);

        // DEBUG
        //  cout << "Created Tag" << endl;
        //  currentTag->printTag();
    }

    // DEBUG: print top_tags
    //  cout << "TOP TAGS" << endl;
    //  for(auto tag : top_tags)
    //  {
    //      tag.second->printTag();
    //  }

    // read the queries one at a time and give the output
    for (; q > 0; q--)
    {
        getline(cin, line);
        position = 0;

        // top-level tag name
        for (end = position + 1; line[end] != '~' && line[end] != '.'; end++)
            ;

        if (top_tags.find(line.substr(position, end - position)) == top_tags.end())
        {
            cout << "Not Found!" << endl;
            continue;
        }

        // get the tag
        Tag *currentTag = top_tags[line.substr(position, end - position)];

        bool no_such_child = false;
        // if it is . for nested tags, keep going
        while (line[end] == '.')
        {
            position = end + 1;

            // next tag name
            for (end = position + 1; line[end] != '~' && line[end] != '.'; end++)
                ;

            if (currentTag->children.find(line.substr(position, end - position)) == currentTag->children.end())
            {
                cout << "Not Found!" << endl;
                no_such_child = true;
                break;
            }

            // go to that tag
            currentTag = currentTag->children[line.substr(position, end - position)];
        }
        if (no_such_child)
            continue;

        // go past ~ for attribute name, until end of line (not including newline)
        position = end + 1;
        end = line.length() - 1;

        // DEBUG: see what attribute we're trying to read
        //  cout << "loooking for '" << line.substr(position,end-position+1) << "' in tag '" << currentTag->tagname << "'" << endl;
        //  currentTag->printTag();

        auto iter = currentTag->attributes.find(line.substr(position, end - position + 1));
        if (iter == currentTag->attributes.end())
            cout << "Not Found!" << endl;
        else
            cout << (*iter).second << endl;
    }

    //delete the top-level tags, which will recursively delete the children
    for (auto tagPair : top_tags)
    {
        delete tagPair.second;
    }

    return 0;
}
