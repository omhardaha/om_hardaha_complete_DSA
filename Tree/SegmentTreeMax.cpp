#include <bits/stdc++.h>
using namespace std;
class SegMentTree
{
    vector<int> arr;
    vector<int> seg;
    int low = 0;
    int high = 0;

public:
    SegMentTree(vector<int> arr1)
    {
        seg = vector<int>(4 * arr1.size(), INT_MIN);
        arr = arr1;
        high = arr1.size() - 1;
        build(0, 0, 9);
    }
    int build(int i, int low, int high)
    {
        if (low == high)
        {
            return seg[i] = arr[low];
        }
        int mid = (low + high) / 2;
        return seg[i] = max(build(i * 2 + 1, low, mid), build(i * 2 + 2, mid + 1, high));
    }
    int rangMaxHelper(int i, int low, int high, int l, int r)
    {
        if (low >= l && high <= r)
        {
            return seg[i];
        }
        if (high < l || low > r)
        {
            return INT_MIN;
        }
        int mid = (low + high) / 2;
        return max(rangMaxHelper(i * 2 + 1, low, mid, l, r), rangMaxHelper(i * 2 + 2, mid + 1, high, l, r));
    }
    int rangMax(int l, int r)
    {
        return rangMaxHelper(0, 0, 9, l, r);
    }
};
int main()
{
    vector<int> arr = {10, 12, 3, 6, 3, 5, 9, 2, 5, 46};
    SegMentTree seg(arr);
    cout << seg.rangMax(8, 9);
    return 0;
}