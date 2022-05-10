#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885?
int solve(vector<vector<int>> &grid, vector<vector<vector<int>>> &dp, int i, int j1, int j2)
{
    if (j1 < 0 || j2 < 0 || j1 >= grid[0].size() || j2 >= grid[0].size())
    {
        return -1e8;
    }

    if (i == grid.size() - 1)
    {
        return (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
    }

    if (dp[i][j1][j2] != -1)
    {
        return dp[i][j1][j2];
    }

    int next = 0;
    for (int p1 = -1; p1 <= 1; p1++)
    {
        for (int p2 = -1; p2 <= 1; p2++)
        {
            next = max(next, solve(grid, dp, i + 1, j1 + p1, j2 + p2));
        }
    }
    int curMax = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];

    return dp[i][j1][j2] = curMax + next;
}

int maximumChocolates(vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));
    return solve(grid, dp, 0, 0, grid[0].size() - 1);
}

// Time Complexity = N x M x M x 3
// Space Complexity = N x M x M x 3
int main()
{
    vector<vector<int>> GRID = {{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}};
    cout << maximumChocolates(GRID);
    return 0;
}