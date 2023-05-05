// change 12hr time to 24hr time

#include <bits/stdc++.h>

using namespace std;

/////////////////////////////
// MY CODE START

string timeConversion(string s)
{
    int hour = stoi(s.substr(0, 2));
    if (s[8] == 'P')
    {
        if (hour < 12)
            hour += 12;
    }
    else // AM
    {
        if (hour == 12)
            hour = 0;
    }
    if (hour < 10)
        return "0" + to_string(hour) + s.substr(2, 6);
    // else
    return to_string(hour) + s.substr(2, 6);
}

// MY CODE END
/////////////////////////////

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
