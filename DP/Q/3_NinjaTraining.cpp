#include <bits/stdc++.h>
using namespace std;
int ninjaTraining(vector<vector<int>> &points, int i, int prev, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        int h = 0;
        for (int j = 0; j < 3; j++)
        {
            if (j != prev)
                h = max(h, points[0][j]);
        }
        return h;
    }
    int l = 0;

    if (dp[i][prev] != -1)
    {
        return dp[i][prev];
    }
    for (int j = 0; j < 3; j++)
    {
        if (prev != j)
        {
            int y = points[i][j] + ninjaTraining(points, i - 1, j, dp);
            l = max(l, y);
        }
    }
    return dp[i][prev] = l;
}
int ninjaTrainingTab(vector<vector<int>> &points)
{
    for (int i = 0; i < points.size(); i++)
    {
        
    }
}
int main()
{
    vector<vector<int>> points = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}};

    vector<vector<int>> dp(points.size(), vector<int>(4, -1));
    // cout << ninjaTraining(points, points.size() - 1, 3, dp);
    cout << ninjaTrainingTab(points); // 210
    return 0;
}