// some obscure reason to make a variadic template?

#include <iostream>
using namespace std;

/////////////////////////////////////////
// MY CODE START

#include <vector>

template <bool... digits>
int reversed_binary_value()
{
    vector<bool> fixed({digits...});
    int sum = 0, cur = 1;
    for (int i = 0; i < fixed.size(); i++, cur *= 2)
    {
        if (fixed[i])
            sum += cur;
    }
    return sum;
}

// MY CODE END
/////////////////////////////////////////

template <int n, bool... digits>
struct CheckValues
{
    static void check(int x, int y)
    {
        CheckValues<n - 1, 0, digits...>::check(x, y);
        CheckValues<n - 1, 1, digits...>::check(x, y);
    }
};

template <bool... digits>
struct CheckValues<0, digits...>
{
    static void check(int x, int y)
    {
        int z = reversed_binary_value<digits...>();
        std::cout << (z + 64 * y == x);
    }
};

int main()
{
    int t;
    std::cin >> t;

    for (int i = 0; i != t; ++i)
    {
        int x, y;
        cin >> x >> y;
        CheckValues<6>::check(x, y);
        cout << "\n";
    }
}
