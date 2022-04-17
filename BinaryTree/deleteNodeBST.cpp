#include <bits/stdc++.h>
using namespace std;
TreeNode *findMin(TreeNode *root)
{
    if (!root->left)
        return root;
    return findMin(root->left);
}
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (!root)
        return root;

    if (root->val > key)
        root->left = deleteNode(root->left, key);

    else if (root->val < key)
        root->right = deleteNode(root->right, key);

    else
    {
        if (!root->left && !root->right)
            return nullptr;
        else if (!root->left)
            return root->right;
        else if (!root->right)
            return root->left;
        else
        {
            TreeNode *minNode = findMin(root->right);
            root->val = minNode->val;
            root->right = deleteNode(root->right, minNode->val);
        }
    }
    return root;
}
int main()
{

    return 0;
}