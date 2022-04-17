#include <bits/stdc++.h>
using namespace std;
int maximumNonAdjacentSumDP(vector<int> &nums, int i, vector<int> &dp)
{
    if (i < 0)
    {
        return 0;
    }
    if (i == 0)
    {
        return nums[i];
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    int left = nums[i] + maximumNonAdjacentSumDP(nums, i - 2, dp);
    int right = 0 + maximumNonAdjacentSumDP(nums, i - 1, dp);
    return dp[i] = max(left, right);
}
int maximumNonAdjacentSumTab(vector<int> &nums)
{
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    for (int i = 1; i < dp.size(); i++)
    {
        int left = dp[i - 1]; // not pick
        int right = INT_MIN;  // pick
        if (i > 1)
            right = dp[i - 2] + nums[i];
        dp[i] = max(left, right);
    }
    return dp[dp.size() - 1];
}

int HouseRobTab(vector<int> &nums)
{
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    for (int i = 1; i < dp.size(); i++)
    {
        int left = dp[i - 1]; // not pick
        int right = nums[i];  // pick
        if (i > 1)
            right = dp[i - 2] + nums[i];
        dp[i] = max(left, right);
    }
    return dp[dp.size() - 1];
}
int main()
{
    vector<int> nums = {1, 2, 3, 1, 3, 5, 8, 1, 9};
    vector<int> dp(nums.size(), -1);
    // cout << maximumNonAdjacentSumDP(nums, nums.size() - 1, dp); // 24
    cout << maximumNonAdjacentSumTab(nums); // 24
    return 0;
}