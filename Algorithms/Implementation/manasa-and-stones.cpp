// a combination-based problem with a shortcut

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

///////////////////////////////
// MY CODE START

vector<int> stones(int n, int a, int b)
{
    // example answer seems to include the zero stone
    n--;

    vector<int> answer;

    // only one possible answer if a==b
    if (a == b)
    {
        answer.push_back(n * a);
        return answer;
    }

    const int smaller = a < b ? a : b;
    const int bigger = a > b ? a : b;
    const int difference = bigger - smaller;
    // smallest possible number is n * smaller + 0 * bigger
    // next smallest is (n-1) * smaller + 1 * bigger
    // etc.
    // so the amount just goes up by difference each time
    int current = n * smaller;
    answer.push_back(current);
    for (int i = 1; i <= n; i++)
    {
        current += difference;
        answer.push_back(current);
    }

    return answer;
}

// MY CODE END
///////////////////////////////

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string T_temp;
    getline(cin, T_temp);

    int T = stoi(ltrim(rtrim(T_temp)));

    for (int T_itr = 0; T_itr < T; T_itr++)
    {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string a_temp;
        getline(cin, a_temp);

        int a = stoi(ltrim(rtrim(a_temp)));

        string b_temp;
        getline(cin, b_temp);

        int b = stoi(ltrim(rtrim(b_temp)));

        vector<int> result = stones(n, a, b);

        for (size_t i = 0; i < result.size(); i++)
        {
            fout << result[i];

            if (i != result.size() - 1)
            {
                fout << " ";
            }
        }

        fout << "\n";
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
