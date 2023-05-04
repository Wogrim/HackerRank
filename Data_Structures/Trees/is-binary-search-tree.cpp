// making sure nodes are placed where they should be

/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.

The Node struct is defined as follows:
    struct Node {
        int data;
        Node* left;
        Node* right;
    }
*/

//////////////////////////////////////
// MY CODE START

bool checkBST(Node *current, int min, int max)
{
    // if we went left at some point to get here, this node must be smaller
    // if we went right at some point to get here, this mode must be larger
    if (current->data <= min || current->data >= max)
        return false;
    if (current->left != nullptr)
    {
        // check the left child (with a new max of this node's data)
        if (checkBST(current->left, min, current->data) == false)
            return false;
    }
    if (current->right != nullptr)
    {
        // check the right child (with a new min of this node's data)
        if (checkBST(current->right, current->data, max) == false)
            return false;
    }
    return true;
}

bool checkBST(Node *root)
{
    const int inf = 1000000;
    return checkBST(root, -inf, inf);
}

// MY CODE END
//////////////////////////////////////
