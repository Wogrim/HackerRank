// string reordering

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/////////////////////////////////////
// MY CODE START

string biggerIsGreater(string w)
{
    // split the string into an array of characters
    vector<char> letters(w.begin(), w.end());

    // find the rightmost letter that has a bigger letter after it
    // swap with the next bigger letter
    // sort the remaining letters smallest to largest
    //  A C F D D => A D C D F
    map<char, int> end;
    for (int i = w.length() - 2; i >= 0; i--)
    {
        // save location of right letter for potential swap later
        end.insert(pair<char, int>(letters[i + 1], i + 1));

        // if right letter is bigger
        if (letters[i] < letters[i + 1])
        {
            // swap with next bigger letter
            int bigger = (*end.upper_bound(letters[i])).second;
            char temp = letters[i];
            letters[i] = letters[bigger];
            letters[bigger] = temp;

            // sort remaining letters smallest to largest
            sort(letters.begin() + i + 1, letters.end());

            // put it back in a string
            return string(letters.begin(), letters.end());
        }
    }
    // already sorted from biggest to smallest; impossible
    return "no answer";
}

// MY CODE END
/////////////////////////////////////

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string T_temp;
    getline(cin, T_temp);

    int T = stoi(ltrim(rtrim(T_temp)));

    for (int T_itr = 0; T_itr < T; T_itr++)
    {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

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
