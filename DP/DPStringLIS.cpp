#include <bits/stdc++.h>
using namespace std;

// LIS Qs -
// https://leetcode.com/problems/longest-increasing-subsequence/
// https://leetcode.com/problems/largest-divisible-subset/
// https://leetcode.com/problems/longest-string-chain/
// https://leetcode.com/problems/number-of-longest-increasing-subsequence/
// https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1/

void replaceCeiling(vector<int> &lis, int val)
{
    int low = 0;
    int high = lis.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (val > lis[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    lis[low] = val;
};
int lengthOfLIS(vector<int> &grid)
{
    vector<int> lis;
    lis.push_back(grid[0]);

    for (int i = 1; i < grid.size(); i++)
    {
        if (lis[lis.size() - 1] < grid[i])
        {
            lis.push_back(grid[i]);
        }
        else
        {
            replaceCeiling(lis, grid[i]);
        }
    }
    return lis.size();
}
int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLIS(nums);
    return 0;
}