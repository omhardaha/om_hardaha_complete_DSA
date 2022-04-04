#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> name;
    unordered_set<int> name;
    unordered_map<int, int> map;
    stack<int> st;
    priority_queue<pair<int, int>> max_heap;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    vector<vector<int>> grid(5, vector<int>(5));

    sort(grid.begin(), grid.end());
    reverse(grid.begin(), grid.end());

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            cout << grid[i][j];
        }
    }

    for (auto row : grid)
    {
        for (auto i : row)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}