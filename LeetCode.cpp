#include <bits/stdc++.h>
using namespace std;
int i, j, k;
int mod = 1e9 + 7;

int isSafe(vector<vector<int>> &board, int i, int j)
{
    return !(i < 0 || j < 0 || j >= board[0].size() || i >= board.size() || board[i][j] == 1);
}

// edges to graph forming -->

vector<vector<int>>graph(n);
for(auto i : edges){
    graph[i[0]].push_back(i[1]);
    graph[i[1]].push_back(i[0]);
}

int main()
{
    vector<int> nums = {1, 24, 35, 6, 24, 23};
    int maxElem = *max_element(nums.begin(), nums.end());
    int minElem = *min_element(nums.begin(), nums.end());
    int countN = count(nums.begin(), nums.end(), 6);
    int sum = accumulate(nums.begin(), nums.end(), 0);
    
    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());

    priority_queue<int> max_heap;
    priority_queue<pair<int, int>> max_heap_pair;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap_pair;

    vector<int> dp;
    dp = vector<int>(nums.size(), -1);

    vector<vector<int>> dp2;
    dp2 = vector<vector<int>>(nums.size(), vector<int>(nums.size(), -1));

    vector<vector<vector<int>>> dp3;
    dp3 = vector<vector<vector<int>>>(nums.size(), vector<vector<int>>(nums.size(), vector<int>(nums.size(), -1)));

    map<int, int> map1;
    unordered_map<int, int> map2;

    unordered_set<int> map3;
    set<int, int> map4;

    vector<int> prefix = nums;

    for (int i = 1; i < nums.size(); i++) {
        prefix[i] += prefix[i - 1];
    }

    for(auto &i : nums ) cout<<i; cout<<endl;

    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp.size(); j++)
        {
            cout << dp[i];
        }
        cout << endl;
    }
    return 0;
}

// int solve(vector<int> &nums, vector<int> &dp, int i)
// {
//     if (i >= nums.size())
//     {
//         return INT_MAX;
//     }
//     if (i == nums.size() - 1)
//     {
//         return nums[i];
//     }
//     int left = solve(nums, dp, i + 1, j);
//     int right = solve(nums, dp, i, j + 1);
//     return dp[i] = min(left, right);
// }

// int solve(vector<vector<int>> &grid, int i, int j)
// {
//     if (i < 0 || j < 0 || j >= grid[0].size() || i >= grid.size())
//     {
//         return INT_MAX;
//     }
//     if (i == grid.size() - 1 && j == grid[0].size() - 1)
//     {
//         return grid[i][j];
//     }
//     int left = solve(grid,i + 1, j);
//     int right = solve(grid, i, j + 1);
//     return dp[i][j] = grid[i][j] + min(left, right);
// }

// int solve(vector<vector<int>> &board, int i, int j)
// {
//     if (i == board.size() - 1 && j == board[0].size() - 1)
//     {
//         return 0;
//     }

//     if (dp[i][j] != -1)
//     {
//         return dp[i][j];
//     }
//     int r = 1e9;
//     int l = 1e9;
//     int u = 1e9;
//     int d = 1e9;
//     board[i][j] = 1;

//     if (isSafe(board, i, j + 1))
//         r = colCost[j + 1] + solve(board, i, j + 1);

//     if (isSafe(board, i, j - 1))
//         l = colCost[j - 1] + solve(board, i, j - 1);

//     if (isSafe(board, i - 1, j))
//         u = rowCost[i - 1] + solve(board, i - 1, j);

//     if (isSafe(board, i + 1, j))
//         d = rowCost[i + 1] + solve(board, i + 1, j);

//     board[i][j] = 0;

//     return dp[i][j] = min(d, min(u, min(r, l)));
// }


// LEVEL ORDER TRAVERSAL
TreeNode* reverseOddLevels(TreeNode* root) {
        
        bool rev = 1;
        queue<TreeNode* >Q;
        Q.push(root);
        
        while(!Q.empty()){
            
            int size = Q.size();
            vector<TreeNode* >arr;
            
            while(size--){
                
                auto node = Q.front();
                
                if(node->left){
                   arr.push_back(node->left);
                   Q.push(node->left);
                }
                
                if(node->right){
                   arr.push_back(node->right);
                   Q.push(node->right);
                }
                
                Q.pop();
            }
            
            if(rev){
                int l = 0;
                int r = arr.size()-1;
                while(l<r){
                    swap(arr[l]->val,arr[r]->val);
                    l++;r--;
                }
            }
            rev = !rev;
        }
        
        return root;
    }
