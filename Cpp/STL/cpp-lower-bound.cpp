// lower_bound() requires sorted, gives iterator to first element >= val

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    // create vector
    int n;
    cin >> n;
    vector<int> vn(n);
    for (int i = 0; i < n; i++)
        cin >> vn[i];
    //note: already sorted

    // read queries
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int val;
        cin >> val;

        //get lower bound
        vector<int>::iterator lower = lower_bound(vn.begin(), vn.end(), val);

        // output whether or not we found val and 1-indexed location
        if (*lower == val)
            cout << "Yes " << lower - vn.begin() + 1 << endl;
        else
            cout << "No " << lower - vn.begin() + 1 << endl;
    }

    return 0;
}
