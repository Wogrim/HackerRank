// ultra basic ineritance, not even using polymorphism

#include <iostream>

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
    void description()
    {
        cout << "In an isosceles triangle two sides are equal\n";
    }
};

int main()
{
    Isosceles isc;
    isc.isosceles();
    isc.description();
    // call the parent class's method
    isc.triangle();
    return 0;
}
