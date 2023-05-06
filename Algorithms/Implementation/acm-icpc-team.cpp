// this could be done with a bitset approach instead

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

//////////////////////////////////////
// MY CODE START

vector<int> acmTeam(vector<string> topic)
{
    int n = topic.size();
    // for each person make a list of topics they don't know
    // and a set of topics they do know
    vector<list<int>> dunno(n);
    vector<set<int>> known(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < topic[i].length(); j++)
        {
            if (topic[i][j] == '1')
                known[i].insert(j);
            else
                dunno[i].push_back(j);
        }
    }
    // the answer is highest count, and number of teams that meet that
    vector<int> most(2);
    // for each possible combination of people
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // look up unknown topics of person i in known topics of person j
            int team = known[i].size();
            for (int a : dunno[i])
            {
                if (known[j].find(a) != known[j].end())
                    team++;
            }

            if (team > most[0])
            {
                most[0] = team;
                most[1] = 1;
            }
            else if (team == most[0])
                most[1]++;
        }
    }
    return most;
}

// MY CODE END
//////////////////////////////////////

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<string> topic(n);

    for (int i = 0; i < n; i++)
    {
        string topic_item;
        getline(cin, topic_item);

        topic[i] = topic_item;
    }

    vector<int> result = acmTeam(topic);

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
