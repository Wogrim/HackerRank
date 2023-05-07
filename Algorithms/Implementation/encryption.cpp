// transform a string to an "encrypted" version

#include <bits/stdc++.h>

using namespace std;

/////////////////////////////////
// MY CODE START

string encryption(string s)
{
    // make a copy of the string without spaces to skip grid building
    // and so we can calculate grid dimensions
    vector<char> nospaces;
    nospaces.reserve(s.length());
    for (int i = 0; i < s.length(); i++)
        if (s[i] != ' ')
            nospaces.push_back(s[i]);
    int n = nospaces.size();
    int columns = ceil(sqrt(n));

    // TODO: faster way to build a string?
    string answer;
    answer.reserve(n + columns);
    // loop through each 'column'
    for (int col = 0; col < columns; col++)
    {
        for (int j = col; j < n; j += columns)
        {
            answer.push_back(nospaces[j]);
        }
        answer.push_back(' ');
    }
    return answer;
}

// MY CODE END
/////////////////////////////////

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
