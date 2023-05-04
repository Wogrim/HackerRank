// height of the tree is the max depth of a node

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

    ////////////////////////////
    // MY CODE START

    int height(Node *root)
    {
        // note: height (or depth) of the root node is 0
        if (root == nullptr)
            return -1;
        // else
        return 1 + max(height(root->left), height(root->right));
    }

    // MY CODE END
    ////////////////////////////

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

    int height = myTree.height(root);
    std::cout << height;

    return 0;
}
