// simplified leaderboard problem

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/////////////////////////////////
// MY CODE START

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player)
{
    vector<int> answers(player.size());
    // map leaderboard score to rank
    //(not useful for a leaderboard that actually changes)
    // could do equivalent with an array and binary search
    map<int, int> leaderboard;
    int prev = -1;
    int rank = 0;
    for (int score : ranked)
    {
        if (score != prev)
        {
            rank++;
            leaderboard[score] = rank;
            prev = score;
        }
    }
    // DEBUG
    for (pair<int, int> l : leaderboard)
    {
        cout << l.first << ' ' << l.second << endl;
    }
    // find where in the leaderboard the player would be
    map<int, int>::iterator p;
    for (int i = 0; i < player.size(); i++)
    {
        // upper bound will give the next higher score
        // so this score will be one rank behind that
        // or end() if this is highest
        p = leaderboard.upper_bound(player[i]);
        if (p == leaderboard.end())
            answers[i] = 1;
        else
            answers[i] = p->second + 1;
    }
    return answers;
}

// MY CODE END
/////////////////////////////////

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string ranked_count_temp;
    getline(cin, ranked_count_temp);

    int ranked_count = stoi(ltrim(rtrim(ranked_count_temp)));

    string ranked_temp_temp;
    getline(cin, ranked_temp_temp);

    vector<string> ranked_temp = split(rtrim(ranked_temp_temp));

    vector<int> ranked(ranked_count);

    for (int i = 0; i < ranked_count; i++)
    {
        int ranked_item = stoi(ranked_temp[i]);

        ranked[i] = ranked_item;
    }

    string player_count_temp;
    getline(cin, player_count_temp);

    int player_count = stoi(ltrim(rtrim(player_count_temp)));

    string player_temp_temp;
    getline(cin, player_temp_temp);

    vector<string> player_temp = split(rtrim(player_temp_temp));

    vector<int> player(player_count);

    for (int i = 0; i < player_count; i++)
    {
        int player_item = stoi(player_temp[i]);

        player[i] = player_item;
    }

    vector<int> result = climbingLeaderboard(ranked, player);

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
