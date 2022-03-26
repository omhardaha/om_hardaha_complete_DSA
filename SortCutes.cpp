#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> name;
    set<int> name;
    unordered_map<int, int> map;

    stack<int> st;
    priority_queue<pair<int, int>> max_heap;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    vector<vector<int>> grid(5, vector<int>(5));
    sort(grid.begin(), grid.end());
    reverse(grid.begin(), grid.end());

    return 0;
}