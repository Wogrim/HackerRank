// class template and template specialization

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

//////////////////////////////////////////////////
// MY CODE START

// class template
template <class T>
class AddElements
{
private:
    T value;

public:
    // constructor
    AddElements(T v) : value(v) {}
    // generic add
    T add(const T &other)
    {
        return value + other;
    }
};

// template specialization
template <>
class AddElements<string>
{
private:
    string value;

public:
    //constructor
    AddElements(string v) : value(v) {}
    // string concatenation
    string concatenate(string other)
    {
        return value + other;
    }
};

// MY CODE END
//////////////////////////////////////////////////

int main()
{
    int n, i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        string type;
        cin >> type;
        if (type == "float")
        {
            double element1, element2;
            cin >> element1 >> element2;
            AddElements<double> myfloat(element1);
            cout << myfloat.add(element2) << endl;
        }
        else if (type == "int")
        {
            int element1, element2;
            cin >> element1 >> element2;
            AddElements<int> myint(element1);
            cout << myint.add(element2) << endl;
        }
        else if (type == "string")
        {
            string element1, element2;
            cin >> element1 >> element2;
            AddElements<string> mystring(element1);
            cout << mystring.concatenate(element2) << endl;
        }
    }
    return 0;
}
