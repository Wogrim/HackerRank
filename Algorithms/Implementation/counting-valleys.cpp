// counting valleys based on a cumulative altitude calculation

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

////////////////////////
// MY CODE START

int countingValleys(int steps, string path)
{
    int vcount = 0, h = 0, gain;
    for (int i = 0; i < path.length(); i++)
    {
        gain = (path[i] == 'U' ? 1 : -1);
        h += gain;
        // if we went up to get to sea level, we just finished a valley
        if (h == 0 && gain == 1)
            vcount++;
    }
    return vcount;
}

// MY CODE END
////////////////////////

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string steps_temp;
    getline(cin, steps_temp);

    int steps = stoi(ltrim(rtrim(steps_temp)));

    string path;
    getline(cin, path);

    int result = countingValleys(steps, path);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
