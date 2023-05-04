// top-to-bottom, left-to-right order of the tree

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

    /////////////////////////////
    // MY CODE START

    void levelOrder(Node *root)
    {
        // for each depth, an array of values left to right
        vector<vector<int>> answers;

        // get the answers
        levelOrder(root, answers, 0);

        // print the answers
        for (vector<int> row : answers)
            for (int val : row)
                cout << val << ' ';
    }

private:
    void levelOrder(Node *current, vector<vector<int>> &answers, int depth)
    {
        if (current == nullptr)
            return;
        // new depth; add another vector<int> to answers
        if (depth == answers.size())
            answers.emplace_back();
        // put this node's value in answers
        answers[depth].push_back(current->data);
        // go left then right so answers are filled in correct order
        levelOrder(current->left, answers, depth + 1);
        levelOrder(current->right, answers, depth + 1);
    }

    // MY CODE END
    /////////////////////////////

}; // End of Solution

int main()
{

    Solution myTree;
    Node *root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0)
    {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.levelOrder(root);

    return 0;
}
