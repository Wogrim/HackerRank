// transforming a string in exactly k operations

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

//////////////////////////////////
// MY CODE START

string appendAndDelete(string s, string t, int k)
{
    // if k is at least length of s plus t,
    // we can delete all and append all
    // extra moves used by delete on empty string
    if (s.length() + t.length() <= k)
        return "Yes";
    // figure out how much is matching already
    int matching = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == t[i])
            matching++;
        else
            break;
    }
    // moves needed to delete and add characters
    int moves = (s.length() - matching) + (t.length() - matching);
    // we need k >= moves, and k-moves must be even to add/delete extra moves
    if (k >= moves && (k - moves) % 2 == 0)
        return "Yes";
    // else
    return "No";
}

// MY CODE END
//////////////////////////////////

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = appendAndDelete(s, t, k);

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
