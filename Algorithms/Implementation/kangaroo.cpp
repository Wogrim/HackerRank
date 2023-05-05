// calculating where 2 different-speed objects will meet

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

////////////////////////////////////
// MY CODE START

string kangaroo(int x1, int v1, int x2, int v2)
{
    // x1 + v1*j = x2 + v2*j
    // x1-x2 = (v2-v1)*j
    // (x1-x2)/(v2-v1) = j
    // they meet if j is a positive whole number of jumps
    // avoid divide by zero (which is when they have same speed)

    if (v2 == v1)
    {
        if (x1 == x2)
            return "YES";
        // else
        return "NO";
    }
    int j = (x1 - x2) / (v2 - v1);
    if (j > 0 && (x1 - x2) % (v2 - v1) == 0)
        return "YES";
    // else
    return "NO";
}

// MY CODE END
////////////////////////////////////

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int x1 = stoi(first_multiple_input[0]);

    int v1 = stoi(first_multiple_input[1]);

    int x2 = stoi(first_multiple_input[2]);

    int v2 = stoi(first_multiple_input[3]);

    string result = kangaroo(x1, v1, x2, v2);

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
