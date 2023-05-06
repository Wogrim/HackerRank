// page-turning calculation

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

//////////////////////////
// MY CODE START

int pageCount(int n, int p)
{
    // from the front, whether p is even or odd, p/2 is the number of pages to turn
    int front = p / 2;
    // from the back, if n is odd, (n-p)/2 is the number of pages to turn
    // but if n is even, (n-p+1)/2 is the number of pages to turn
    int back;
    if (n % 2 == 1)
        back = (n - p) / 2;
    else
        back = (n - p + 1) / 2;
    return min(front, back);
}

// MY CODE END
//////////////////////////

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    int result = pageCount(n, p);

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
