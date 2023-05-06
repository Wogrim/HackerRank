// simple: jump as far as you can unless it's a bad cloud

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

//////////////////////////////
// MY CODE START

int jumpingOnClouds(vector<int> c)
{
    // always jump 2 clouds forward if possible
    // else jump 1 (solution always possible)
    int jumps = 0;
    int lastcloud = c.size() - 1;
    for (int i = 0; i < lastcloud; jumps++)
    {
        // if we are within 2 clouds of the last one,
        // it is the last jump
        if (i >= lastcloud - 2)
            return jumps + 1;
        // else
        // jump 2 if we can, else 1
        if (c[i + 2] == 0)
            i += 2;
        else
            i += 1;
    }
    // DEBUG: shouldn't get here
    cout << "uh oh" << endl;
    return jumps;
}

// MY CODE END
//////////////////////////////

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split(rtrim(c_temp_temp));

    vector<int> c(n);

    for (int i = 0; i < n; i++)
    {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = jumpingOnClouds(c);

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
