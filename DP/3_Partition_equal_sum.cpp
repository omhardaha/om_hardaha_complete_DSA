#include <bits/stdc++.h>
using namespace std;
bool subSetSum(vector<int> &nums, int i, int sum, vector<vector<bool>> &dp)
{
  if (sum == 0)
    return true;
  if (sum < 0 || i < 0)
    return false;

  if (dp[i][sum] != true)
    return false;

  return dp[i][sum] = subSetSum(nums, i - 1, sum, dp) || subSetSum(nums, i - 1, sum - nums[i], dp);
}
bool canPartition(vector<int> &nums)
{
  int sum = 0;
  for (int i : nums)
    sum += i;
  if (sum % 2 == 1)
    return false;

  vector<vector<bool>> dp(nums.size() + 1, vector<bool>(sum / 2 + 1, true));

  return subSetSum(nums, nums.size() - 1, sum / 2, dp);
}

int main()
{

  vector<int> s = {1, 5, 11, 5};
  cout << canPartition(s);
  return 0;
}