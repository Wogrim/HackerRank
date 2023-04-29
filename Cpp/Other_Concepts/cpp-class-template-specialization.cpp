// class template and template specialization and a little enums

#include <iostream>
using namespace std;
enum class Fruit
{
    apple,
    orange,
    pear
};
enum class Color
{
    red,
    green,
    orange
};

template <typename T>
struct Traits;

/////////////////////////////////
// MY CODE START

template <>
struct Traits<Fruit>
{
    static string name(int index)
    {
        switch (static_cast<Fruit>(index))
        {
        case Fruit::apple:
            return "apple";
        case Fruit::orange:
            return "orange";
        case Fruit::pear:
            return "pear";
        default:
            return "unknown";
        }
    }
};
template <>
struct Traits<Color>
{
    static string name(int index)
    {
        switch (static_cast<Color>(index))
        {
        case Color::red:
            return "red";
        case Color::green:
            return "green";
        case Color::orange:
            return "orange";
        default:
            return "unknown";
        }
    }
};

// MY CODE END
/////////////////////////////////

int main()
{
    int t = 0;
    std::cin >> t;

    for (int i = 0; i != t; ++i)
    {
        int index1;
        std::cin >> index1;
        int index2;
        std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}
