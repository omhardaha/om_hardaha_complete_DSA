#include <bits/stdc++.h>
using namespace std;

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
                que.push(perenet[f]);
            }
        };
    };
    return count;
}
int main()
{
   
    return 0;
}