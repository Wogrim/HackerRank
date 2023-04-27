// some simple string usage, notice you can change individual letters

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    
    //how big the strings are
    cout << a.size() << " " << b.size() << endl;

    //concatenate strings
    cout << a + b << endl;

    //swap first letters
    char temp = a[0];
    a[0] = b[0];
    b[0] = temp;

    cout << a << " " << b << endl;
    return 0;
}
