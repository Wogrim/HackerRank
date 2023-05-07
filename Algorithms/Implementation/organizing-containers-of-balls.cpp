// just check counts of balls vs size of containers

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

//////////////////////////////////////////
// MY CODE START

string organizingContainers(vector<vector<int>> container)
{
    const int n = container.size();

    // total counts for each ball color
    vector<int> counts(n);
    // size of each container
    vector<int> sizes(n);

    for (int ci = 0; ci < n; ci++)
    {
        for (int bi = 0; bi < n; bi++)
        {
            counts[bi] += container[ci][bi];
            sizes[ci] += container[ci][bi];
        }
    }

    // sort so we can match container size with ball count
    sort(counts.begin(), counts.end());
    sort(sizes.begin(), sizes.end());

    // not possible if any of the counts is not equal to container size
    bool possible = true;
    for (int i = 0; i < n; i++)
    {
        if (counts[i] != sizes[i])
        {
            possible = false;
            break;
        }
    }

    return possible ? "Possible" : "Impossible";
}

// MY CODE END
//////////////////////////////////////////

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<vector<int>> container(n);

        for (int i = 0; i < n; i++)
        {
            container[i].resize(n);

            string container_row_temp_temp;
            getline(cin, container_row_temp_temp);

            vector<string> container_row_temp = split(rtrim(container_row_temp_temp));

            for (int j = 0; j < n; j++)
            {
                int container_row_item = stoi(container_row_temp[j]);

                container[i][j] = container_row_item;
            }
        }

        string result = organizingContainers(container);

        fout << result << "\n";
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
