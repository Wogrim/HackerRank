// dumb problem based on figuring out valid magic squares

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

////////////////////////
// MY CODE START

int formingMagicSquare(vector<vector<int>> s)
{
    const int n = 3;
    int sarr[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            sarr[i][j] = s[i][j];
    // magic constant is sum of all elements divided by n
    // sum from 1 to n^2 is (n^2)(n^2+1)/2
    // which will be 15 for n = 3
    int magic_constant = 15;
    // for n = 3, 5 has to be in the middle for
    // row, column, and 2 diagonals to sum to 15
    // 9 can only go with 1 and 5 or 2 and 4, it can't be on a diagonal
    // this limits 9 to 4 possible slots
    // 1 only has one possible slot based on 9
    // 2 can be to either side of 9 with 4 in the other
    // because of the diagonals, this forces set locations for 8 and 6
    // this in turn forces 3 and 7 in remaining slots to make 8 3 4 and 6 7 2
    // so there's 8 possible magic squares, which are really just 1 with rotation/mirroring
    // they are:
    int answers[8][3][3] =
        {
            {{2, 9, 4},
             {7, 5, 3},
             {6, 1, 8}},
            {{4, 9, 2},
             {3, 5, 7},
             {8, 1, 6}},
            {{6, 7, 2},
             {1, 5, 9},
             {8, 3, 4}},
            {{8, 3, 4},
             {1, 5, 9},
             {6, 7, 2}},
            {{6, 1, 8},
             {7, 5, 3},
             {2, 9, 4}},
            {{8, 1, 6},
             {3, 5, 7},
             {4, 9, 2}},
            {{2, 7, 6},
             {9, 5, 1},
             {4, 3, 8}},
            {{4, 3, 8},
             {9, 5, 1},
             {2, 7, 6}}};
    // just figure out which of these arrays is closest to the one we are changing
    int best_cost = 100; // array values are within 1 to 9, so worst case scenario is much lower
    for (int a = 0; a < 8; a++)
    {
        int this_cost = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                this_cost += abs(answers[a][i][j] - sarr[i][j]);
        if (this_cost < best_cost)
            best_cost = this_cost;
    }

    return best_cost;
}

// MY CODE END
////////////////////////

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);

    for (int i = 0; i < 3; i++)
    {
        s[i].resize(3);

        string s_row_temp_temp;
        getline(cin, s_row_temp_temp);

        vector<string> s_row_temp = split(rtrim(s_row_temp_temp));

        for (int j = 0; j < 3; j++)
        {
            int s_row_item = stoi(s_row_temp[j]);

            s[i][j] = s_row_item;
        }
    }

    int result = formingMagicSquare(s);

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
