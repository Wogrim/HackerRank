// use properties of modular division to figure out the conflicts

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

///////////////////////////////////
// MY CODE START

int nonDivisibleSubset(int k, vector<int> s)
{
    // conflicts occur when (a+b)%k == 0 for any a and b in the set
    // which also means (a%k +b%k)%k == 0
    // which means if c%k == a%k, c also will conflict with b
    // so we want to remove the fewer a%k or b%k numbers

    // get counts of (numbers in array mod k)
    vector<int> mods(k);
    for (int x : s)
        mods[x % k]++;

    // start with all of the numbers and remove the conflicts
    int answer = s.size();

    // 0 self-conflicts
    if (mods[0] > 1)
        answer -= mods[0] - 1;

    // slightly different for even or odd
    if (k % 2 == 0)
    {
        // EVEN
        //  k/2 self-conflicts
        if (mods[k / 2] > 1)
            answer -= mods[k / 2] - 1;

        // main conflicts
        for (int i = 1; i < k / 2; i++)
        {
            if (mods[i] >= 1 && mods[k - i] >= 1)
                answer -= mods[i] >= mods[k - i] ? mods[k - i] : mods[i];
        }
    }
    else
    {
        // ODD
        // main conflicts
        for (int i = 1; i <= k / 2; i++)
        {
            if (mods[i] >= 1 && mods[k - i] >= 1)
                answer -= mods[i] >= mods[k - i] ? mods[k - i] : mods[i];
        }
    }

    return answer;
}

// MY CODE END
///////////////////////////////////

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s_temp_temp;
    getline(cin, s_temp_temp);

    vector<string> s_temp = split(rtrim(s_temp_temp));

    vector<int> s(n);

    for (int i = 0; i < n; i++)
    {
        int s_item = stoi(s_temp[i]);

        s[i] = s_item;
    }

    int result = nonDivisibleSubset(k, s);

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

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
