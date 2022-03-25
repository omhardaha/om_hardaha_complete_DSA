#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/burning-tree/1/#
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void minTimePutPerentHelper(TreeNode *root, TreeNode *per, unordered_map<TreeNode *, TreeNode *> &perenet)
{
    if (!root)
    {
        return;
    }
    perenet[root] = per;
    minTimePutPerentHelper(root->left, root, perenet);
    minTimePutPerentHelper(root->right, root, perenet);
}
vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    vector<int> ans;
    unordered_map<TreeNode *, TreeNode *> perenet;
    minTimePutPerentHelper(root, nullptr, perenet);
    unordered_map<TreeNode *, bool> visited;
    visited[target] = true;
    queue<TreeNode *> que;
    que.push(target);
    // k-=1;
    k++;
    while (!que.empty() && k > 0)
    {
        k--;
        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *f = que.front();
            if (k == 0)
            {
                ans.push_back(f->val);
            }
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
    return ans;
}
int main()
{
    /*
                     1
                  /     \
                 2       3
                /      /
               4     7
                \
                8
          */
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(7);
    root->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(8);
    vector<int> ans = distanceK(root, root->left->left, 6);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}