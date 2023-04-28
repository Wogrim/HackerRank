// erase() removes a single element or range, requires valid iterator(s)

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    // create vector
    int n;
    cin >> n;
    vector<int> integers(n);
    for (int i = 0; i < n; i++)
        cin >> integers[i];

    // remove single
    int remove;
    cin >> remove;
    remove--;  // 1-based
    integers.erase(integers.begin() + remove);

    // remove range
    int removeA, removeB;
    cin >> removeA >> removeB;
    removeA--;  // 1-based
    removeB--;  // 1-based
    integers.erase(integers.begin()+removeA,integers.begin()+removeB);

    // output
    cout << integers.size() << endl;
    for (int i = 0; i < integers.size(); i++)
        cout << integers[i] << ' ';

    return 0;
}
