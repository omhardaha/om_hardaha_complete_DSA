#include <bits/stdc++.h>
using namespace std;

int uniquePathsTab(vector<vector<int>> &grid)
{
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (i == 0 && j == 0)
            {
                dp[0][0] = 1;
            }
            else
            {
                int top = 0;
                int left = 0;
                if (i > 0)
                    top = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = top + left;
            }
        }
    }
    return dp[grid.size() - 1][grid[0].size() - 1];
}

int uniquePathsObstaclesTab(vector<vector<int>> &grid)
{
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == -1)
            {
                dp[i][j] = 0;
                continue;
            }
            if (i == 0 && j == 0)
            {
                dp[0][0] = 1;
            }
            else
            {
                int top = 0;
                int left = 0;
                if (i > 0)
                    top = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = (top + left) % 1000000007;
            }
        }
    }
    return dp[grid.size() - 1][grid[0].size() - 1];
}

int minSumPathSumTab(vector<vector<int>> &grid)
{
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (i == 0 && j == 0)
            {
                dp[0][0] = grid[0][0];
            }
            else
            {
                int top = INT_MAX;
                int left = INT_MAX;
                if (i > 0)
                    top = dp[i - 1][j] + grid[i][j];
                if (j > 0)
                    left = dp[i][j - 1] + grid[i][j];
                dp[i][j] = min(top, left);
            }
        }
    }
    return dp[grid.size() - 1][grid[0].size() - 1];
}

int main()
{
    int m = 4, n = 4;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    vector<vector<int>> grid(m, vector<int>(n, 0));
    // cout << uniquePathsDP(grid, dp, grid.size() - 1, grid[0].size() - 1);
    cout << uniquePathsTab(grid);
    return 0;
}