#include <bits/stdc++.h>
using namespace std;
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
    // set<int> map;
    // unordered_set<int> map;
    // unordered_set<pair<int,int>> map;

    unordered_map<int, int> map1;
    map1[65] = 3;
    map1[2] = 4;
    map1[5] = 3;
    // cout << map1.begin()->second << endl;
    map1[map1.begin()->first] = 44;
    // map1.begin()->first;
    for (auto i : map1)
    {
        cout << i.first << " " << i.second << endl;
    }
    // stack<int> st;
    // priority_queue<int> max_heap;
    // priority_queue<int, vector<int>, greater<int>> min_heap;

    // priority_queue<pair<int, int>> max_heap;
    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
    // priority_queue<int, vector<int>, greater<int>> min_heap;
    // vector<vector<int>> grid(100000, vector<int>(100000));

    // int solve(vector<vector<int>>& grid,vector<vector<int>>&dp,int i,int j){
    //     if (i < 0 || j < 0 ||j >= grid[0].size() || i >= grid.size() ) return INT_MAX;
    //     if(i==grid.size()-1 && j==grid[0].size()-1)return grid[i][j];
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     int left = solve(grid,dp,i+1,j);
    //     int right = solve(grid,dp,i,j+1);
    //     return dp[i][j] =grid[i][j] + min(left,right);
    // }

    // 2d
    //   vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(),-1));

    // 3d
    //   vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));
    //   return solve(grid,dp,0);

    // sort(grid.begin(), grid.end());
    // reverse(grid.begin(), grid.end());

    // for (int i = 0; i < grid.size(); i++)
    // {
    //     for (int j = 0; j < grid[0].size(); j++)
    //     {
    //         cout << grid[i][j];
    //     }
    // }

    // for (auto row : grid)
    // {
    //     for (auto i : row)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}