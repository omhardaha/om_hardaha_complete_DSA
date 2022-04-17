#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, vector<int> wt, vector<int> val, vector<vector<int>> &dp, int i)
{
    if (i == 0 || W == 0)
    {
        return 0;
    }
    if (dp[i][W] != -1)
    {
        return dp[i][W];
    }
    if (wt[i - 1] <= W)
    {
        return dp[i][W] = max(knapSack(W, wt, val, dp, i - 1), (val[i - 1] + knapSack(W - wt[i - 1], wt, val, dp, i - 1)));
    }
    return dp[i][W] = knapSack(W, wt, val, dp, i - 1);
}
int main()
{
    int W = 7;
    vector<int> val = {1, 2, 3, 4, 6, 3, 1};
    vector<int> wt = {4, 5, 1, 7, 8, 6, 7};
    vector<vector<int>> dp(val.size() + 1, vector<int>(W + 1, -1));
    cout << knapSack(W, wt, val, dp, val.size());
    return 0;
}