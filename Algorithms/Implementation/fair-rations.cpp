// go from front to back making the numbers even

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

//////////////////////////////////
// MY CODE END

string fairRations(vector<int> B)
{
    // we always distribute 2 loaves, so impossible if there
    // are an odd number of existing loaves
    // but our algorithm will just check at the end

    // go from front to back giving a loaf
    // to anyone with an odd number of loaves,
    // plus the person behind them
    //(everyone in front has even number of loaves)
    int count = 0;
    for (int i = 0; i < B.size() - 1; i++)
    {
        if (B[i] % 2 == 1)
        {
            // B[i]++; //never used
            B[i + 1]++;
            count += 2;
        }
    }
    // if last one is odd, impossible
    if (B[B.size() - 1] % 2 == 1)
        return "NO";
    // else
    return to_string(count);
}

// MY CODE END
//////////////////////////////////

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    string B_temp_temp;
    getline(cin, B_temp_temp);

    vector<string> B_temp = split(rtrim(B_temp_temp));

    vector<int> B(N);

    for (int i = 0; i < N; i++)
    {
        int B_item = stoi(B_temp[i]);

        B[i] = B_item;
    }

    string result = fairRations(B);

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
