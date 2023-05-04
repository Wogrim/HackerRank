// problem based on an incorrect drawing of a tree

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

    //////////////////////////////////
    // MY CODE START

    void topView(Node *root)
    {
        // traverse the tree twice to ignore depths
        // top-most nodes going left
        vector<int> lefts;
        getLefts(root, lefts, 0);
        // top-most nodes going right
        vector<int> rights;
        getRights(root, rights, 0);

        // print, don't print root twice
        for (int i = lefts.size() - 1; i > 0; i--)
            cout << lefts[i] << ' ';
        for (int i = 0; i < rights.size(); i++)
            cout << rights[i] << ' ';
    }

private:
    void getLefts(Node *current, vector<int> &lefts, int h)
    {
        if (current == nullptr)
            return;
        // first node at this h is top
        if (h == lefts.size())
            lefts.push_back(current->data);
        getLefts(current->left, lefts, h + 1);
        getLefts(current->right, lefts, h - 1);
    }
    void getRights(Node *current, vector<int> &rights, int h)
    {
        if (current == nullptr)
            return;
        // first node at this h is top
        if (h == rights.size())
            rights.push_back(current->data);
        getRights(current->right, rights, h + 1);
        getRights(current->left, rights, h - 1);
    }

    // MY CODE END
    //////////////////////////////////

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

    myTree.topView(root);

    return 0;
}
