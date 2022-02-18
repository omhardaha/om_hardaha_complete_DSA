// Lowest ComaxPathSumhelperon Ancestor in a Binary Tree
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
int maxPathSumhelper(Node *root, int &maxi)
{
  if (root == nullptr)
    return 0;
  int left = max(0, maxPathSumhelper(root->left, maxi));
  int right = max(0, maxPathSumhelper(root->right, maxi));
  maxi = max(maxi, (root->val + left + right));
  return root->val + max(left, right);
}

int maxPathSum(Node *root)
{
  int ans = root->val;
  maxPathSumhelper(root, ans);
  return ans;
}

int main()
{
  //        4
  //     2      6
  //  1   3   5   7
  //                 8
  //                   9
  Node *root = newNode(4);
  root->left = newNode(2);
  root->right = newNode(6);
  root->left->left = newNode(1);
  root->left->right = newNode(3);
  root->right->left = newNode(5);
  root->right->right = newNode(7);
  root->right->right->right = newNode(8);
  root->right->right->right->right = newNode(9);

  cout << maxPathSum(root);
  return 0;
}