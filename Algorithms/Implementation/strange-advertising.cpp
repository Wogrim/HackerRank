// 1/2 like it and share to 3 friends each the next day

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

////////////////////////
// MY CODE START

int viralAdvertising(int n)
{
    int likesTotal = 0, likesi;
    int shared = 5;
    for (int i = 1; i <= n; i++)
    {
        likesi = shared / 2;
        likesTotal += likesi;
        // for the next day
        shared = likesi * 3;
    }
    return likesTotal;
}

// MY CODE END
////////////////////////

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    int result = viralAdvertising(n);

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
