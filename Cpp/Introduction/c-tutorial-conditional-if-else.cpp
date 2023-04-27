// supposed to be if / else if tutorial but switch is good here

#include <iostream>
#include <string>

using namespace std;

// declarations of helper functions that must be defined later
string ltrim(const string &);
string rtrim(const string &);

int main()
{
    //getting the input by reading the whole line
    string n_temp;
    getline(cin, n_temp);
    int n = stoi(ltrim(rtrim(n_temp)));

    switch (n)
    {
    case 1:
        printf("one");
        break;
    case 2:
        printf("two");
        break;
    case 3:
        printf("three");
        break;
    case 4:
        printf("four");
        break;
    case 5:
        printf("five");
        break;
    case 6:
        printf("six");
        break;
    case 7:
        printf("seven");
        break;
    case 8:
        printf("eight");
        break;
    case 9:
        printf("nine");
        break;
    default:
        printf("Greater than 9");
    }

    return 0;
}
