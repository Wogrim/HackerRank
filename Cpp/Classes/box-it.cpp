// a Box class which does a few things

#include <iostream>

using namespace std;

class Box
{
private:
    int l, b, h;

public:
    // default constructor
    Box() : Box(0, 0, 0) {}
    // general constructor
    Box(int length, int breadth, int height) : l(length), b(breadth), h(height) {}
    // copy constructor
    Box(Box &other) : Box(other.getLength(), other.getBreadth(), other.getHeight()) {}

    // getters
    int getLength() { return l; }
    int getBreadth() { return b; }
    int getHeight() { return h; }

    // volume calculation
    long long CalculateVolume() { return ((long long)l) * b * h; }

    // overload less-than to compare Box < Box
    bool operator<(Box &other)
    {
        if (l < other.getLength())
            return true;
        // else
        if (l == other.getLength())
        {
            if (b < other.getBreadth())
                return true;
            // else
            if (b == other.getBreadth())
            {
                if (h < other.h)
                    return true;
            }
        }
        // if none of the above conditions were met
        return false;
    }
};

// overload ostream << to use cout << Box
ostream &operator<<(ostream &out, Box &B)
{
    out << B.getLength() << ' ' << B.getBreadth() << ' ' << B.getHeight();
    return out;
}

//////////////////////////////////////////////////

void check2()
{
    int n;
    cin >> n;
    Box temp;
    for (int i = 0; i < n; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            cout << temp << endl;
        }
        if (type == 2)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            cout << temp << endl;
        }
        if (type == 3)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if (NewBox < temp)
            {
                cout << "Lesser\n";
            }
            else
            {
                cout << "Greater\n";
            }
        }
        if (type == 4)
        {
            cout << temp.CalculateVolume() << endl;
        }
        if (type == 5)
        {
            Box NewBox(temp);
            cout << NewBox << endl;
        }
    }
}

int main()
{
    check2();
}