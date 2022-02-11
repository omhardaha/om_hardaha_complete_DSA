#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s)
{
    string ans;
    unordered_map<char, int> temp;
    for (char &i : s)
        temp[i]++;

    priority_queue<pair<int, char>> max_heap;

    for (auto p : temp)
    {
        max_heap.push({p.second, p.first});
    }

    while (!max_heap.empty())
    {
        int repeat = max_heap.top().first;
        char value = max_heap.top().second;
        for (int i = 0; i < repeat; i++)
        {
            ans += value;
        }
        max_heap.pop();
    }

    return ans;
}
vector<int> frequencySort(vector<int> &nums)
{
    vector<int> ans;
    unordered_map<int, int> temp;
    for (int &i : nums)
        temp[i]++;

    priority_queue<pair<int, int>> max_heap;

    for (auto p : temp)
    {
        max_heap.push({p.second, p.first});
    }

    while (!max_heap.empty())
    {
        int repeat = max_heap.top().first;
        char value = max_heap.top().second;
        for (int i = 0; i < repeat; i++)
        {
            ans.push_back(value);
        }
        max_heap.pop();
    }

    return ans;
}
int main()
{
    vector<int> t = {6, 5, 6, 6, 5, 6, 6, 6, 9};

    vector<int> ans = frequencySort(t);
    string s = frequencySort("oooommmmharrdaha");
    cout<<s<<endl;
    for (auto i : t)
        cout << i << " ";
    cout << endl;
    for (auto i : ans)
        cout << i << " ";

    return 0;
}