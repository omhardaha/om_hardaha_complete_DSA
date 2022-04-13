#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/frog-jump_3621012
int frogJumpDP(vector<int> &nums, int i, vector<int> &dp)
{
    if (i == 0)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    if (i == 1)
    {
        return abs(nums[i] - nums[i - 1]);
    }
    int left = frogJumpDP(nums, i - 2, dp) + abs(nums[i] - nums[i - 2]);
    int right = frogJumpDP(nums, i - 1, dp) + abs(nums[i] - nums[i - 1]);
    return dp[i] = min(left, right);
}

int frogJumpTab(vector<int> &nums)
{
    vector<int> dp(nums.size(), 0);
    dp[0] = 0; // base case
    for (int i = 1; i < dp.size(); i++)
    {
        int left = dp[i - 1] + abs(nums[i] - nums[i - 1]);
        int right = INT_MAX;
        if (i > 1)
            right = dp[i - 2] + abs(nums[i] - nums[i - 2]);

        dp[i] = min(left, right);
    }
    return dp[dp.size() - 1];
}

int frogJumpKTab(vector<int> &nums, int k)
{
    vector<int> dp(nums.size(), 0);
    dp[0] = 0; // base case
    for (int i = 1; i < dp.size(); i++)
    {
        int left = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                left = min(left, dp[i - j] + abs(nums[i] - nums[i - j]));
            }
            dp[i] = left;
        }
    }
    return dp[dp.size() - 1];
}

int main()
{
    // vector<int> nums = {10, 20, 30, 10};
    vector<int> nums = {10, 30, 40, 50, 20};
    vector<int> dp(nums.size(), -1);
    // cout << frogJumpDP(nums, nums.size() - 1, dp);
    // cout << frogJumpTab(nums);
    cout << frogJumpKTab(nums, 3);
    return 0;
}