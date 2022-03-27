#include <bits/stdc++.h>
using namespace std;
// https://www.spoj.com/problems/INVCNT/
int main()
{
    // array of n distinct positive integers
    vector<int> arr = {100000, 100, 1000, 100000000};
    map<int, int> store;
    for (auto i : arr)
    {
        store[i] = 0;
    }
    int inCrement = 1;

    for (auto &i : store)
    {
        i.second = inCrement++;
    }
    for (auto &i : arr)
    {
        i = store[i];
    }
    for (auto &i : arr)
    {
        cout << i << " ";
    }
    vector<int> countArr(100000, 0);
    int maxCount = 0;
    // for(auto )
    // cout << (10000);
    return 0;
}