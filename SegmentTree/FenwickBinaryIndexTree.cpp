#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/range-sum-query-mutable/
class FenwickTree
{
public:
    vector<int> arrCopy;
    vector<int> fenWick; // 10
    FenwickTree(vector<int> arr)
    {
        fenWick = vector<int>(arr.size() + 1);
        arrCopy = vector<int>(arr.size() + 1);
        for (int i = 0; i < arr.size(); i++)
        {
            update(i + 1, arr[i]);
            arrCopy[i + 1] = arr[i];
        }
    }
    void replace(int i, int val)
    {
        update(i, val - arrCopy[i]);
        arrCopy[i + 1] = val;
    }
    void update(int i, int val)
    {
        while (i < fenWick.size())
        {
            fenWick[i] += val;
            i = i + (i & (~i + 1));
        }
    }
    int calSum(int i)
    {
        int ans = 0;
        while (i > 0)
        {
            ans += fenWick[i];
            i -= (i & (~i + 1));
        }
        return ans;
    }
    int rangeSum(int l, int r)
    {
        return calSum(r) - calSum(l - 1);
    }
};

int main()
{
    vector<int> arr = {12, 3, 6, 3, 5, 9, 2, 5, 46}; // 9
    FenwickTree fg(arr);
    fg.replace(1, 4);
    cout << fg.rangeSum(1, 3);
    return 0;
}