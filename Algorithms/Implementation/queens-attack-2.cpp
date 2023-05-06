// for each direction see how far the queen can go

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/////////////////////////////////////
// MY CODE START

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles)
{
    int attacks = 0;
    // make a set of the obstacles for quicker lookup
    set<pair<int, int>> obs;
    for (vector<int> o : obstacles)
    {
        // maybe worth only inserting ones that are on the row/column/diagonal?
        obs.insert(make_pair(o[0], o[1]));
    }

    // go each direction until obstacle or end of board (1-indexed)
    // up row
    for (int i = 1;; i++)
    {
        int a = r_q + i;
        if (a > n)
            break;
        if (obs.find(make_pair(a, c_q)) != obs.end())
            break;
        // else
        attacks++;
    }
    // down row
    for (int i = 1;; i++)
    {
        int a = r_q - i;
        if (a < 1)
            break;
        if (obs.find(make_pair(a, c_q)) != obs.end())
            break;
        // else
        attacks++;
    }
    // up column
    for (int i = 1;; i++)
    {
        int b = c_q + i;
        if (b > n)
            break;
        if (obs.find(make_pair(r_q, b)) != obs.end())
            break;
        // else
        attacks++;
    }
    // down column
    for (int i = 1;; i++)
    {
        int b = c_q - i;
        if (b < 1)
            break;
        if (obs.find(make_pair(r_q, b)) != obs.end())
            break;
        // else
        attacks++;
    }
    // up-up diagonal
    for (int i = 1;; i++)
    {
        int a = r_q + i;
        int b = c_q + i;
        if (a > n || b > n)
            break;
        if (obs.find(make_pair(a, b)) != obs.end())
            break;
        // else
        attacks++;
    }
    // up-down diagonal
    for (int i = 1;; i++)
    {
        int a = r_q + i;
        int b = c_q - i;
        if (a > n || b < 1)
            break;
        if (obs.find(make_pair(a, b)) != obs.end())
            break;
        // else
        attacks++;
    }
    // down-up diagonal
    for (int i = 1;; i++)
    {
        int a = r_q - i;
        int b = c_q + i;
        if (a < 1 || b > n)
            break;
        if (obs.find(make_pair(a, b)) != obs.end())
            break;
        // else
        attacks++;
    }
    // down-down diagonal
    for (int i = 1;; i++)
    {
        int a = r_q - i;
        int b = c_q - i;
        if (a < 1 || b < 1)
            break;
        if (obs.find(make_pair(a, b)) != obs.end())
            break;
        // else
        attacks++;
    }
    return attacks;
}

// MY CODE END
/////////////////////////////////////

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string second_multiple_input_temp;
    getline(cin, second_multiple_input_temp);

    vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

    int r_q = stoi(second_multiple_input[0]);

    int c_q = stoi(second_multiple_input[1]);

    vector<vector<int>> obstacles(k);

    for (int i = 0; i < k; i++)
    {
        obstacles[i].resize(2);

        string obstacles_row_temp_temp;
        getline(cin, obstacles_row_temp_temp);

        vector<string> obstacles_row_temp = split(rtrim(obstacles_row_temp_temp));

        for (int j = 0; j < 2; j++)
        {
            int obstacles_row_item = stoi(obstacles_row_temp[j]);

            obstacles[i][j] = obstacles_row_item;
        }
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

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
