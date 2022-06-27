#include <bits/stdc++.h>
using namespace std;
int i, j, k;

int isSafe(vector<vector<int>> &board, int i, int j)
{
    if (i < 0 || j < 0 || j >= board[0].size() || i >= board.size())
    {
        return false;
    }
    return true;
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
    vector<int> dp(nums.size(), -1);
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
    vector<vector<vector<int>>> dp(nums.size(), vector<vector<int>>(nums.size(), vector<int>(nums.size(), -1)));

    vector<int> prefix = nums;
    for (int j = 1; j < nums.size(); j++)
    {
        prefix[i] += prefix[i - 1];
    }

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

// int solve(vector<vector<int>> &grid, vector<vector<int>> &dp, int i, int j)
// {
//     if (i < 0 || j < 0 || j >= grid[0].size() || i >= grid.size())
//     {
//         return INT_MAX;
//     }
//     if (i == grid.size() - 1 && j == grid[0].size() - 1)
//     {
//         return grid[i][j];
//     }
//     int left = solve(grid, dp, i + 1, j);
//     int right = solve(grid, dp, i, j + 1);
//     return dp[i][j] = grid[i][j] + min(left, right);
// }
