// another dumb example

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Triangle
{
public:
    void triangle()
    {
        cout << "I am a triangle\n";
    }
};

class Isosceles : public Triangle
{
public:
    void isosceles()
    {
        cout << "I am an isosceles triangle\n";
    }
};

///////////////////////////////
// MY CODE START

class Equilateral : public Isosceles
{
public:
    void equilateral()
    {
        cout << "I am an equilateral triangle" << endl;
    }
};

// MY CODE END
///////////////////////////////

int main()
{

    Equilateral eqr;
    eqr.equilateral();
    eqr.isosceles();
    eqr.triangle();
    return 0;
}
