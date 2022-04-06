#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1/
bool comp(pair<float, float> a, pair<float, float> b)
{
    return (a.first / a.second) > (b.first / b.second);
}
int main()
{
    int W = 15;
    vector<int> values = {6, 10, 18, 3, 15, 5, 7};
    vector<int> weight = {1, 2, 4, 1, 5, 3, 7};
    vector<pair<float, float>> p;
    for (int i = 0; i < values.size(); i++)
    {
        p.push_back({values[i], weight[i]});
    }
    sort(p.begin(), p.end(), comp);
    float Profit = 0;
    int i = 0;
    while (W > 0 && i < values.size())
    {
        float curValue = p[i].first;
        float curweight = p[i].second;
        if (W >= curweight)
        {
            Profit += curValue;
            W -= curweight;
        }
        else
        {
            float x = W / curweight;
            float pro = curValue * x;
            Profit += pro;
            break;
        }
        i++;
    }
    cout << Profit;
    return 0;
}