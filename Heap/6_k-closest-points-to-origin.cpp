#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    vector<vector<int>> ans;
    priority_queue<pair<double, vector<int>>> max_heap;

    for (auto &i : points)
    {

        max_heap.push({sqrt((abs(i[0] * i[0]) + abs(i[1] * i[1]))), i});
        if (max_heap.size() > k)
            max_heap.pop();
    }

    while (!max_heap.empty())
    {
        ans.push_back(max_heap.top().second);
        max_heap.pop();
    }
    return ans;
}
int main()
{
    vector<vector<int>> t{{1, 3}, {13, 3}, {14, 3}, {15, 3}, {71, 3}, {-2, 2}, {0, 2}};
    int k = 5;

    vector<vector<int>> ans = kClosest(t, k);

    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}