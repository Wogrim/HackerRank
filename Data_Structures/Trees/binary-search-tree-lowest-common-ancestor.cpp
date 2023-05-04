// find where two values would diverge on the tree

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

    //////////////////////////
    // MY CODE START

    Node *lca(Node *root, int v1, int v2)
    {
        Node *answer = root;
        // go down the tree until you find a node where
        // they won't be on the same side of it
        while (true)
        {
            if (v1 > answer->data && v2 > answer->data)
                answer = answer->right;
            else if (v1 < answer->data && v2 < answer->data)
                answer = answer->left;
            else
                return answer;
        }
    }

    // MY CODE END
    //////////////////////////

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

    int v1, v2;
    std::cin >> v1 >> v2;

    Node *ans = myTree.lca(root, v1, v2);

    std::cout << ans->data;

    return 0;
}
