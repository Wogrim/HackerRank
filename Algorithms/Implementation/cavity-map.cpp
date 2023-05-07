// 2D array calculation

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

///////////////////////////
// MY CODE START

vector<string> cavityMap(vector<string> grid)
{
    const int n = grid.size();
    // make a list of all the locations that should be an X
    list<pair<int, int>> cavities;
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            if (grid[i][j] > grid[i + 1][j] && grid[i][j] > grid[i - 1][j] && grid[i][j] > grid[i][j + 1] && grid[i][j] > grid[i][j - 1])
            {
                cavities.push_back(make_pair(i, j));
            }
        }
    }

    // put the Xs in the grid
    for (pair<int, int> cavity : cavities)
        grid[cavity.first][cavity.second] = 'X';

    return grid;
}

// MY CODE END
///////////////////////////

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> grid(n);

    for (int i = 0; i < n; i++)
    {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = cavityMap(grid);

    for (size_t i = 0; i < result.size(); i++)
    {
        fout << result[i];

        if (i != result.size() - 1)
        {
            fout << "\n";
        }
    }

    fout << "\n";

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
