// map is the ordered BST variety; for hashmap use unordered_map

#include <iostream>
#include <map>

using namespace std;

int main()
{
    //map of student name -> marks
    map<string, int> marks;

    //queries
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int query_type, score;
        string name;
        cin >> query_type >> name;
        switch (query_type)
        {
        case 1:
            // add; if name not in map, its marks are first defaulted to 0
            cin >> score;
            marks[name] += score;
            break;
        case 2:
            // remove student from the map
            marks.erase(name);
            break;
        case 3:
            // read; if name not in map, its marks are defaulted to 0
            cout << marks[name] << endl;
        }
    }

    return 0;
}
