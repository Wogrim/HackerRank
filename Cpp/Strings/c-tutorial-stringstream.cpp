// a stringstream can be used as an input stream like cin

#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

vector<int> parseInts(string str)
{
    //vector to be returned
    vector<int> integers;
    //convert the string to a stringstream
    stringstream ss(str);
    int integer;
    char comma;

    do
    {
        //read an integer
        ss >> integer;
        //put it in the vector
        integers.push_back(integer);
        // loop if it grabs a comma
    } while (ss >> comma);

    return integers;
}

int main()
{
    string str;
    cin >> str;
    
    vector<int> integers = parseInts(str);

    for (int i = 0; i < integers.size(); i++)
        cout << integers[i] << "\n";

    return 0;
}
