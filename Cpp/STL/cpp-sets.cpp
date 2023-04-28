// set is the ordered BST variety; for hashset use unordered_set

#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> numbers;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int query_type, val;
        cin >> query_type >> val;
        switch (query_type)
        {
        case 1:
            //insert value
            numbers.insert(val);
            break;
        case 2:
            //erase by value
            numbers.erase(val);
            break;
        case 3:
            //check if value in set
            if (numbers.find(val) == numbers.end())
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
    }
    return 0;
}
