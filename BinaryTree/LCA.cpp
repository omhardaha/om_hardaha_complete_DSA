// Lowest Common Ancestor in a Binary Tree
#include <bits/stdc++.h>
using namespace std;

// A Binary Tree node
struct Node
{
    int val;
    struct Node *left, *right;
};

// Utility function creates a new binary tree node with given val
Node *newNode(int k)
{
    Node *temp = new Node;
    temp->val = k;
    temp->left = temp->right = NULL;
    return temp;
}

bool path(Node *root, int val, vector<int> &temp)
{
    if (root == nullptr)
        return false;
    temp.push_back(root->val);

    if (root->val == val)
        return true;

    if (path(root->left, val, temp))
        return true;

    if (path(root->right, val, temp))
        return true;
    return false;
}

Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    if (!root)
        return nullptr;

    if (root->val == p->val || root->val == q->val)
        return root;

    Node *l = lowestCommonAncestor(root->left, p, q);
    Node *r = lowestCommonAncestor(root->right, p, q);

    if (l && r)
        return root; // sorthand

    if (l == nullptr)
        return r;
    if (r == nullptr)
        return l;

    return nullptr;
}
int main()
{
    //        1
    //     2      3
    //  4   5   6   7
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << lowestCommonAncestor(root, root->right->left, root->right->right)->val; // lca(root, 6, 7)
    return 0;
}