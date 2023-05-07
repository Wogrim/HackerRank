// another string/int conversion problem

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

///////////////////////////////////
// MY CODE START

bool singlekap(int n)
{
    int d = to_string(n).length();
    long n2 = static_cast<long>(n) * n;
    // cases where we can't split the string
    if (n2 < 10)
        return n2 == d ? true : false;
    string n2s = to_string(n2);
    string left = n2s.substr(0, n2s.length() - d);
    string right = n2s.substr(n2s.length() - d, d);
    if (stoi(left) + stoi(right) == n)
        return true;
    // else
    return false;
}

void kaprekarNumbers(int p, int q)
{
    int count = 0;
    for (int i = p; i <= q; i++)
    {
        if (singlekap(i))
        {
            cout << i << ' ';
            count++;
        }
    }
    if (count == 0)
        cout << "INVALID RANGE" << endl;
    else
        cout << endl;
}

// MY CODE END
///////////////////////////////////

int main()
{
    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    kaprekarNumbers(p, q);

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
