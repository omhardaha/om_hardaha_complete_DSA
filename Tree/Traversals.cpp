#include <bits/stdc++.h>
using namespace std;
// All Questions Of Traversals
// https://leetcode.com/problems/binary-tree-right-side-view
// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1/
// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
// https://leetcode.com/problems/binary-tree-level-order-traversal/
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
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

vector<int> topView(TreeNode *root)
{
    unordered_map<int, int> map;
    vector<int> ans;
    int minLevel = 0;
    int maxLevel = 0;
    queue<pair<TreeNode *, int>> que;
    que.push({root, 0});

    while (!que.empty())
    {
        TreeNode *Node = que.front().first;
        int width = que.front().second;
        que.pop();
        if (map.find(width) == map.end())
        {
            map[width] = Node->val;
        }
        if (Node->left)
        {
            que.push({Node->left, width - 1});
        }
        if (Node->right)
        {
            que.push({Node->right, width + 1});
        }

        minLevel = min(minLevel, width);
        maxLevel = max(maxLevel, width);
    }

    for (int i = minLevel; i <= maxLevel; i++)
    {
        ans.push_back(map[i]);
    }
    return ans;
}

vector<int> bottomView(TreeNode *root)
{
    unordered_map<int, int> map;
    vector<int> ans;
    int minLevel = 0;
    int maxLevel = 0;
    queue<pair<TreeNode *, int>> que;
    que.push({root, 0});

    while (!que.empty())
    {
        TreeNode *Node = que.front().first;
        int width = que.front().second;
        que.pop();
        map[width] = Node->val;
        if (Node->left)
        {
            que.push({Node->left, width - 1});
        }
        if (Node->right)
        {
            que.push({Node->right, width + 1});
        }

        minLevel = min(minLevel, width);
        maxLevel = max(maxLevel, width);
    }

    for (int i = minLevel; i <= maxLevel; i++)
    {
        ans.push_back(map[i]);
    }
    return ans;
}

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;

    queue<TreeNode *> temp;
    temp.push(root);
    while (!temp.empty())
    {
        int i = temp.size();
        vector<int> littleAns;

        while (i--)
        {
            TreeNode *t = temp.front();
            temp.pop();
            littleAns.push_back(t->val);
            if (t->left)
                temp.push(t->left);
            if (t->right)
                temp.push(t->right);
        }
        ans.push_back(littleAns);
    }
    return ans;
}

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;

    queue<TreeNode *> temp;
    temp.push(root);
    bool flag = false;

    while (!temp.empty())
    {
        int i = temp.size();
        vector<int> littleAns;

        while (i--)
        {
            TreeNode *t = temp.front();
            temp.pop();
            littleAns.push_back(t->val);
            if (t->left)
                temp.push(t->left);
            if (t->right)
                temp.push(t->right);
        }
        if (flag)
        {
            reverse(littleAns.begin(), littleAns.end());
            flag = false;
        }
        else
        {
            flag = true;
        }
        ans.push_back(littleAns);
    }
    return ans;
}

void boundaryHelperLeft(TreeNode *root, vector<int> &ans)
{
    if (!root)
    {
        return;
    }
    ans.push_back(root->val);
    if (root->left)
    {
        boundaryHelperLeft(root->left, ans);
    }
    else
    {
        boundaryHelperLeft(root->right, ans);
    }
}
void boundaryHelperRight(TreeNode *root, vector<int> &ans)
{
    if (!root)
    {
        return;
    }
    if (root->right)
    {
        boundaryHelperRight(root->right, ans);
    }
    else
    {
        boundaryHelperRight(root->left, ans);
    }
    if (root->left || root->right)
    {
        ans.push_back(root->val);
    }
}
void boundaryHelperBottom(TreeNode *root, vector<int> &ans)
{
    if (!root)
    {
        return;
    }
    if (!root->left & !root->right)
    {
        ans.push_back(root->val);
    }
    boundaryHelperBottom(root->left, ans);

    boundaryHelperBottom(root->right, ans);
}
vector<int> boundary(TreeNode *root)
{
    vector<int> ans;
    ans.push_back(root->val);
    boundaryHelperLeft(root->left, ans);
    if (root->left)
    {
        ans.pop_back();
    }

    if (root->right || root->left)
    {
        boundaryHelperBottom(root, ans);
    }

    boundaryHelperRight(root->right, ans);
    return ans;
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
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(7);
    root->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(8);

    vector<int> ans = boundary(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    // preOrder(root);
    return 0;
}