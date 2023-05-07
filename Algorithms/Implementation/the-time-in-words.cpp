// annoying if/else problem

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

////////////////////////////////
// MY CODE START

const string numbers[30] = {"zero",
                            "one",
                            "two",
                            "three",
                            "four",
                            "five",
                            "six",
                            "seven",
                            "eight",
                            "nine",
                            "ten",
                            "eleven",
                            "twelve",
                            "thirteen",
                            "fourteen",
                            "fifteen",
                            "sixteen",
                            "seventeen",
                            "eighteen",
                            "nineteen",
                            "twenty",
                            "twenty one",
                            "twenty two",
                            "twenty three",
                            "twenty four",
                            "twenty five",
                            "twenty six",
                            "twenty seven",
                            "twenty eight",
                            "twenty nine"};

unordered_map<int, string> special = {{1, "one minute"},
                                      {15, "quarter"},
                                      {30, "half"}};

string timeInWords(int h, int m)
{

    if (m == 0)
        return numbers[h] + " o' clock";

    if (m <= 30)
    {
        if (special.find(m) == special.end())
            return numbers[m] + " minutes past " + numbers[h];
        else
            return special[m] + " past " + numbers[h];
    }
    else
    {
        // minutes from the next hour
        m = 60 - m;
        // hour to next hour
        if (++h == 13)
            h = 1;

        if (special.find(m) == special.end())
            return numbers[m] + " minutes to " + numbers[h];
        else
            return special[m] + " to " + numbers[h];
    }
}

// MY CODE END
////////////////////////////////

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp;
    getline(cin, h_temp);

    int h = stoi(ltrim(rtrim(h_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    string result = timeInWords(h, m);

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
