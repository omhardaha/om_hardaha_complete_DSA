#include <bits/stdc++.h>
using namespace std;
// All Questions Of Traversals
// https://leetcode.com/problems/binary-tree-right-side-view
// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void preOrder(TreeNode *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Right & Left Side View
void rightSideViewHelper(TreeNode *root, vector<int> &ans, int level)
{
    if (!root)
        return;
    if (level == ans.size())
        ans.push_back(root->val);
    rightSideViewHelper(root->right, ans, level + 1);
    rightSideViewHelper(root->left, ans, level + 1);
}
vector<int> rightSideView(TreeNode *root)
{
    vector<int> ans;
    rightSideViewHelper(root, ans, 0);
    return ans;
}

void topViewHelper(TreeNode *root, vector<int> &ans, int width, unordered_map<int, pair<int,int> > &map, int &minLevel, int &maxLevel, int level)
{
    if (!root)
    {
        return;
    }
    // if ( ! map[width] )
    // {
        // map[width] = root->val;
    // }
    minLevel = min(minLevel, width);
    maxLevel = max(maxLevel, width);
    topViewHelper(root->right, ans, width + 1, map, minLevel, maxLevel, level + 1);
    topViewHelper(root->left, ans, width - 1, map, minLevel, maxLevel, level + 1);
}
vector<int> topView(TreeNode *root)
{
    vector<int> ans;
    int minLevel = 0;
    int maxLevel = 0;

    unordered_map<int, pair<int,int> > map;
    topViewHelper(root, ans, 0, map, minLevel, maxLevel, 0);
    for (int i = minLevel; i <= maxLevel; i++)
    {
        // ans.push_back(map[i]);
    }
    return ans;
}
int main()
{
    /*
              1
           /     \
          2       3
         /
        4
         \
         8
   */
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(8);

    // vector<int> ans = rightSideView(root);
    vector<int> ans = topView(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    // preOrder(root);
    return 0;
}