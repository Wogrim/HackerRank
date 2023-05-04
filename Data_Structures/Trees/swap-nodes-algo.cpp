// swapping left and right pointers in certain conditions

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/////////////////////////////////
// MY CODE START

struct Node
{
    int val;
    Node *left;
    Node *right;
    // constructor
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
    // swap left and right pointers
    void swap()
    {
        Node *temp = left;
        left = right;
        right = temp;
    }
};

void inorderPrint(Node *current, vector<int> &answer)
{
    if (current == nullptr)
        return;
    inorderPrint(current->left, answer);
    answer.push_back(current->val);
    inorderPrint(current->right, answer);
}

Node *treeBuilder(vector<vector<int>> &indexes, int i)
{
    // make this node
    Node *answer = new Node(i);
    // make left node if there is one
    if (indexes[i - 1][0] != -1)
        answer->left = treeBuilder(indexes, indexes[i - 1][0]);
    if (indexes[i - 1][1] != -1)
        answer->right = treeBuilder(indexes, indexes[i - 1][1]);
    return answer;
}

void adjust(Node *current, int depth, int k)
{
    if (current == nullptr)
        return;
    // if depth is a multiple of k, swap left and right
    if (depth % k == 0)
        current->swap();
    // adjust children as necessary
    adjust(current->left, depth + 1, k);
    adjust(current->right, depth + 1, k);
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries)
{
    // build the tree
    Node *root = treeBuilder(indexes, 1);

    // for each query, adjust the tree and store answer
    vector<vector<int>> answers(queries.size());
    for (int i = 0; i < queries.size(); i++)
    {
        adjust(root, 1, queries[i]);
        inorderPrint(root, answers[i]);
    }
    return answers;
}

// MY CODE END
/////////////////////////////////

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> indexes(n);

    for (int i = 0; i < n; i++)
    {
        indexes[i].resize(2);

        string indexes_row_temp_temp;
        getline(cin, indexes_row_temp_temp);

        vector<string> indexes_row_temp = split(rtrim(indexes_row_temp_temp));

        for (int j = 0; j < 2; j++)
        {
            int indexes_row_item = stoi(indexes_row_temp[j]);

            indexes[i][j] = indexes_row_item;
        }
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++)
    {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (size_t i = 0; i < result.size(); i++)
    {
        for (size_t j = 0; j < result[i].size(); j++)
        {
            fout << result[i][j];

            if (j != result[i].size() - 1)
            {
                fout << " ";
            }
        }

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
