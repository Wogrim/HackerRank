// stream manipulators for changing how some things are formatted

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int T;
    cin >> T;
    cout << setiosflags(ios::uppercase);
    cout << setw(0xf) << internal;
    while (T--)
    {
        double A;
        cin >> A;
        double B;
        cin >> B;
        double C;
        cin >> C;

        ///////////////////////////////////////////
        // MY CODE START

        // print A without fraction as hex with 0x
        cout << left << hex << showbase << nouppercase << setfill(' ');
        cout << (long)A << endl;

        // print B with +/-, pad with underscores to 15 width, 2 precision
        cout << right << dec << showpos << setw(15) << setfill('_')
             << fixed << setprecision(2);
        cout << B << endl;
        cout << noshowpos;

        // print C scientific notation uppercase 9 precision
        cout << scientific << uppercase << setprecision(9);
        cout << C << endl;

        // MY CODE END
        ///////////////////////////////////////////
    }
    return 0;
}