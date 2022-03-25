#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/burning-tree/1/#
struct Node
{
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};
Node *fire = nullptr;
void minTimePutPerentHelper(Node *root, Node *per, unordered_map<Node *, Node *> &perenet, int &target)
{
    if (!root)
        return;
    if (root->val == target)
    {
        fire = root;
    };
    perenet[root] = per;
    minTimePutPerentHelper(root->left, root, perenet, target);
    minTimePutPerentHelper(root->right, root, perenet, target);
}
int minTime(Node *root, int target)
{
    unordered_map<Node *, Node *> perenet;
    minTimePutPerentHelper(root, nullptr, perenet, target);
    unordered_map<Node *, bool> visited;
    visited[fire] = true;
    queue<Node *> que;
    que.push(fire);
    int count = -1;
    while (!que.empty())
    {
        count++;

        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            Node *f = que.front();
            que.pop();
            if (f->left && !visited[f->left])
            {
                visited[f->left] = true;
                que.push(f->left);
            }
            if (f->right && !visited[f->right])
            {
                visited[f->right] = true;
                que.push(f->right);
            }
            if (perenet[f] && !visited[perenet[f]])
            {
                visited[perenet[f]] = true;
                que.push(perenet[f]);
            }
        };
    };
    return count;
}
int main()
{
    /*
                     1
                  /     \
                 2       3
                /      /
               4      7
                \
                8
          */
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(7);
    root->left->left = new Node(4);
    root->left->left->right = new Node(8);
    cout << minTime(root, 8);
    return 0;
}