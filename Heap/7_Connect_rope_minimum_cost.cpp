#include <bits/stdc++.h>
using namespace std;
int minCost(vector<int> arr)
{
    int cost = 0;

    priority_queue<int, vector<int>, greater<int>> s;

    for (int i = 0; i < arr.size(); i++)
        s.push(arr[i]);

    while (s.size() > 1)
    {
        int l = s.top();
        s.pop();
        int r = s.top();
        s.pop();

        int p = l + r;

        cost += p;
        s.push(p);
    }
    return cost;
}
int main()
{
    vector<int> t{4, 2, 7, 6, 9};
    cout << minCost(t);

    return 0;
}