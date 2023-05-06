// getting digits of a number

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/////////////////////////
// MY CODE START

int findDigits(int n)
{
    // get digit to test by modular division by 10
    int count = 0;
    int remaining = n;
    int test;
    while (remaining > 0)
    {
        cout << remaining << endl;
        test = remaining % 10;
        if (test == 0 || n % test != 0)
        {
            // do nothing
        }
        else
            count++;
        remaining /= 10;
    }
    return count;
}

// MY CODE END
/////////////////////////

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        int result = findDigits(n);

        fout << result << "\n";
    }

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
