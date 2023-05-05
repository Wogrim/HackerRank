// problem with LCM and GCF, probably cleaner way to do this

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

////////////////////////////////////////
// MY CODE START

// for debug
void printV(vector<int> v)
{
    for (int a : v)
        cout << a << ' ';
    cout << endl;
}

// these numbers are small so if they are not prime, they only go up to sqrt(100) which is 10
// but 10, 9, and 8 are not prime so the factors that need to be checked really only go to 7
// but i'm not taking advantage of it
int getTotalX(vector<int> a, vector<int> b)
{
    // get least common multiple of first array
    // for each number in the first array, divide out factors and put in factors array
    int factors[101] = {0};
    for (int ai : a)
    {
        for (int f = 2; f <= ai; f++)
        {
            int count = 0;
            while (ai % f == 0)
            {
                ai /= f;
                count++;
            }
            if (count > factors[f])
                factors[f] = count;
        }
    }
    int lcm = 1;
    for (int i = 2; i <= 100; i++)
    {
        while (factors[i] > 0)
        {
            lcm *= i;
            factors[i]--;
        }
    }
    cout << "lcm: " << lcm << endl; // DEBUG

    // divide second array by LCM
    for (int &bi : b)
    {
        // make sure the lcm does divide into all numbers of the second array
        if (bi % lcm != 0)
            return 0;
        // else
        bi /= lcm;
    }
    printV(b); // DEBUG

    // answer is one for LCM plus all multiples of it that evenly divide into GCF
    // so get the in-common factors of the divided second array
    // first element factors
    int b0 = b[0];
    for (int f = 2; f <= b0; f++)
    {
        int count = 0;
        while (b0 % f == 0)
        {
            b0 /= f;
            count++;
        }
        factors[f] = count;
    }
    // compare remaining element factors
    for (int i = 1; i < b.size(); i++)
    {
        for (int f = 2; f <= 100; f++)
        {
            int count = 0;
            while (b[i] % f == 0)
            {
                b[i] /= f;
                count++;
            }
            factors[f] = min(count, factors[f]);
        }
    }
    // all possible combinations of in-common factors is what we want
    // so 0,1,2...count of each factor
    int combinations = 1;
    for (int f : factors)
    {
        if (f > 0)
        {
            combinations *= f + 1;
        }
    }
    return combinations;
}

// MY CODE END
////////////////////////////////////////

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    string brr_temp_temp;
    getline(cin, brr_temp_temp);

    vector<string> brr_temp = split(rtrim(brr_temp_temp));

    vector<int> brr(m);

    for (int i = 0; i < m; i++)
    {
        int brr_item = stoi(brr_temp[i]);

        brr[i] = brr_item;
    }

    int total = getTotalX(arr, brr);

    fout << total << "\n";

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
