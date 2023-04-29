// a problem about figuring out if/when it will cycle

#include <iostream>
#include <unordered_set>
using namespace std;

// once you get a repeated value, it just cycles and you can stop
// %(2^31) can be replaced with &(2^31 - 1)
// additional optimizations for special values of n, p, q

// apparently this solves all test cases
// but need to prove it only cycles at s or previous
int calculate5(int n, int s, int p, int q)
{
    const int limiter = 2147483647;

    int cur = s;
    int next;

    for (int i = 1; i < n; i++)
    {
        next = ((long)cur * p + q) & limiter;
        if (next == s || next == cur)
            return i;
        cur = next;
    }
    return n;
}

int calculate(int n, int s, int p, int q)
{
    const int limiter = 2147483647;
    unordered_set<int> uniques;
    uniques.reserve(n);

    int cur = s;
    uniques.insert(s);
    for (int i = 1; i < n; i++)
    {
        cur = ((long)cur * p + q) & limiter;
        // as soon as you get one duplicate, the rest will be duplicates
        if (uniques.insert(cur).second == false)
            return i;
    }
    return n;
}

// for p == 1
int calculate2(int n, int s, int q)
{
    // for p = 1 we are just adding q each time
    // it will wrap around and overlap based on properties of q

    // it overlaps based on the smallest power of 2 that divides q
    for (int i = 1; i <= 30; i++)
    {
        if (q % (1 << i) != 0)
        {
            // this power of 2 does not divide q
            i--;
            unsigned max = 2147483648L / (1 << i);
            return max > n ? n : max;
        }
    }
    // shouldn't get here?
    return -1;
}

// for p == 0
int calculate3(int s, int q)
{
    // for p == 0 we just have s then q q q q q
    // assuming n > 1
    return s == q ? 1 : 2;
}

// for q==0
int calculate4(int n, int s, int p)
{
    // there's probably a way to optimize more
    const int limiter = 2147483647;
    unordered_set<int> uniques;
    uniques.reserve(n);

    int cur = s;
    uniques.insert(s);
    for (int i = 1; i < n; i++)
    {
        cur = ((long)cur * p) & limiter;
        // as soon as you get one duplicate, the rest will be duplicates
        if (uniques.insert(cur).second == false)
            return i;
    }
    return n;
}

int main()
{
    // const int mod = 2147483648; //2^31
    const int limiter = 2147483647;

    // could use optimization for p = 1 or q = 0

    int n, s, p, q;
    cin >> n >> s >> p >> q;

    int answer;

    // if(n==1)
    //     answer = 1;
    // else if(p==0)
    //     answer = calculate3(s,q);
    // else if(p==1)
    //     answer = calculate2(n,s,q);
    // else
    answer = calculate5(n, s, p, q);

    cout << answer << endl;

    return 0;
}
