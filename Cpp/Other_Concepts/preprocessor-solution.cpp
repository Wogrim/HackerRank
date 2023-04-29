// preprocessor directives to make the given code work

//////////////////////////////////////////////
// MY CODE START

#define FUNCTION(a, b)           \
    void a(int &x, const int &y) \
    {                            \
        if (y b x)               \
            x = y;               \
    }
#define io(a) cin >> a
#define toStr(a) #a
#define INF 100000000
#define foreach(a, b) for (int b = 0; b < a.size(); b++)

// MY CODE END
//////////////////////////////////////////////

#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    foreach (v, i)
    {
        io(v)[i];
    }
    int mn = INF;
    int mx = -INF;
    foreach (v, i)
    {
        minimum(mn, v[i]);
        maximum(mx, v[i]);
    }
    int ans = mx - mn;
    cout << toStr(Result =) << ' ' << ans;
    return 0;
}
