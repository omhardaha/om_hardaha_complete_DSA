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
        seg = vector<int>(4 * arr1.size(), 0);
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
        return seg[i] = build(i * 2 + 1, low, mid) + build(i * 2 + 2, mid + 1, high);
    }

    int rangMax(int l, int r)
    {
        return rangMaxHelper(0, 0, 9, l, r);
    }
    int rangMaxHelper(int i, int low, int high, int l, int r)
    {
        if (low >= l && high <= r)
        {
            return seg[i];
        }
        if (high < l || low > r)
        {
            return 0;
        }
        int mid = (low + high) / 2;
        return rangMaxHelper(i * 2 + 1, low, mid, l, r) + rangMaxHelper(i * 2 + 2, mid + 1, high, l, r);
    }
    int indexUpdateHelper(int index, int i, int low, int high, int val)
    {
        if (i > high || i < low)
        {
            return seg[index];+
        }
        if (low == high)
        {
            seg[index] += val;
            return seg[index];
        }
        int mid = (low + high) / 2;
        return seg[index] = indexUpdateHelper(2 * index + 1, i, low, mid, val) + indexUpdateHelper(2 * index + 2, i, mid + 1, high, val);
    }
    int indexUpdate(int i, int val)
    {
        indexUpdateHelper(0, i, low, high, val);
        return 0;
    }
};
int main()
{
    vector<int> arr = {10, 12, 3, 6, 3, 5, 9, 2, 5, 46};
    SegMentTree seg(arr);
    seg.indexUpdate(0, 10);
    cout << seg.rangMax(0, 1);
    return 0;
}