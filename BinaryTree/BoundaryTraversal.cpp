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
vector<int> boundary(Node *root)
{
  queue<Node *> p;
  p.push(root);
  vector<int> ans;

  while (!p.empty())
  {
    int size = p.size();
    // int k 
    for (int i = 0; i < size; i++)
    {
      Node *t = p.front();
      p.pop();
      if (i == 0)
      {
        ans.push_back(t->val);
      } 
      //  if(i==size-1){
      //      ans.push_back(t->val);
      //  }
      if (t->left != nullptr)
        p.push(t->left);
      if (t->right != nullptr)
        p.push(t->right);
    }
  }
  p.push(root);

  while (!p.empty())
  {
    int size = p.size();
    // int k 
    for (int i = 0; i < size; i++)
    {
      Node *t = p.front();
      p.pop();
      // if (i == 0)
      // {
      //   ans.push_back(t->val);
      // } 
       if(i==size-1){
           ans.push_back(t->val);
       }
      if (t->left != nullptr)
        p.push(t->left);
      if (t->right != nullptr)
        p.push(t->right);
    }
  }

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
  // root->right->right->right->right = newNode(9);

  vector<int> ans = boundary(root);
  for (auto i : ans)
    cout << i << " ";
  return 0;
}