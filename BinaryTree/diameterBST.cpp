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
int maxDepth(Node *root, int &diameter)
{
  if (!root)
    return 0;
  int left = maxDepth(root->left, diameter);
  int right = maxDepth(root->right, diameter);
  diameter = max(diameter, left + right + 1);
  return 1 + max(left, right);
}

int main()
{
  //        4
  //     2      6
  //  1   3   5   7
  //                 8
  //                   9
  Node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(6);
  root->left->left = newNode(1);
  root->left->right = newNode(3);
  root->right->left = newNode(5);
  root->right->right = newNode(7);
  root->right->right->right = newNode(8);
  root->right->right->right->right = newNode(9);

  int diameter = 0;
  maxDepth(root, diameter);
  cout << diameter;
  return 0;
}