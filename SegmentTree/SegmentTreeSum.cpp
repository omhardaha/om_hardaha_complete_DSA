#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/sum-of-query-ii5310/1/#
class SegmentTreeSum
{
private:
    vector<int> arr;
    vector<int> seg;
    int low = 0;
    int high = 0;

    int build(int i, int low, int high)
    {
        if (low == high)
        {
            return seg[i] = arr[low];
        }
        int mid = (low + high) / 2;
        return seg[i] = build(i * 2 + 1, low, mid) + build(i * 2 + 2, mid + 1, high);
    }

    int rangeSumHelper(int i, int low, int high, int l, int r)
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
        return rangeSumHelper(i * 2 + 1, low, mid, l, r) + rangeSumHelper(i * 2 + 2, mid + 1, high, l, r);
    }

    int updateIndexSumHelper(int index, int i, int low, int high, int val)
    {
        if (i > high || i < low)
        {
            return seg[index];
        }
        if (low == high)
        {
            seg[index] += val;
            return seg[index];
        }
        int mid = (low + high) / 2;
        return seg[index] = updateIndexSumHelper(2 * index + 1, i, low, mid, val) + updateIndexSumHelper(2 * index + 2, i, mid + 1, high, val);
    }

public:
    SegmentTreeSum(vector<int> arr1)
    {
        seg = vector<int>(4 * arr1.size(), 0);
        arr = arr1;
        high = arr1.size() - 1;
        build(0, low, high);
    }

    int rangeSum(int l, int r)
    {
        return rangeSumHelper(0, low, high, l, r);
    }
    void updateIndexSum(int i, int val)
    {
        updateIndexSumHelper(0, i, low, high, val);
    }
};
int main()
{
    vector<int> arr = {10, 12, 3, 6, 3, 5, 9, 2, 5, 46};
    SegmentTreeSum seg(arr);
    // seg.updateIndexSum(0, 10);
    cout << seg.rangeSum(2,7);
    return 0;
}