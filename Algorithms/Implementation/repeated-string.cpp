// typical calculate-instead-of-simulate problem

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/////////////////////////////
// MY CODE START

long repeatedString(string s, long n)
{
    // number of full copies of the string
    long full = n / s.length();
    // number of letter a in the string
    int q = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a')
            q++;
    }
    long total = full * q;

    // partial: # of characters from the start
    int rdr = n % s.length();
    for (int i = 0; i < rdr; i++)
    {
        if (s[i] == 'a')
            total++;
    }
    return total;
}

// MY CODE END
/////////////////////////////

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long result = repeatedString(s, n);

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
