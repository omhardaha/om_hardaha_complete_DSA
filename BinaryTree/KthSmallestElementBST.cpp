// Lowest Common Ancestor in a Binary Tree
#include <bits/stdc++.h>
using namespace std;

// A Binary Tree node
struct Node
{
    int val;
    struct Node *left, *right;
};
Node *newNode(int k)
{
    Node *temp = new Node;
    temp->val = k;
    temp->left = temp->right = NULL;
    return temp;
}
// ABOVE IS IMPLIMENTATION OF TREE

// Code Starts Here -----
bool inorder(Node *root, int &k, int &m, int &ans)
{
    if (!root)
        return false;

    if (inorder(root->left, k, m, ans))
        return true;
    if (k == m)
    {
        ans = root->val;
        return true;
    }
    else
    {
        m++;
    }
    if (inorder(root->right, k, m, ans))
        return true;
    return false;
}
int kthSmallest(Node *root, int k)
{
    int ans = 0;
    int m = 1;
    inorder(root, k, m, ans);
    return ans;
}
int main()
{
    //        4
    //     2      6
    //  1   3   5   7
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(5);
    root->right->right = newNode(7);
    cout << kthSmallest(root, 5); // lca(root, 6, 7)

    //for kth largest element = count number of nodes and minis then then find kth smallest
    return 0;
}