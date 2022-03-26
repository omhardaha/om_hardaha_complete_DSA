#include <bits/stdc++.h>
using namespace std;

class SegmentTreeSumWithLazyUpdates
// also calles as Lazy Propagation in Segment Tree
{
private:
    vector<int> arr;
    vector<int> seg;
    vector<int> lazy;
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
        if (low != high)
        {
            lazy[i * 2 + 1] += lazy[i];
            lazy[i * 2 + 2] += lazy[i];
        }
        lazy[i] = 0;
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

    int rangeSumUpdateHelper(int index, int low, int high, int l, int r, int val)
    {
        if (high < l || low > r)
        {

            return seg[index];
        }
        int mid = (low + high) / 2;
        if (low >= l && high <= r)
        {
            seg[index] += (lazy[index] * (high - low + 1));
            if (low != high)
            {
                lazy[index * 2 + 1] += lazy[index];
                lazy[index * 2 + 2] += lazy[index];
            }
            lazy[index] = 0;
            if (low == high) // last node
            {
                seg[index] += lazy[index] + val;
                return seg[index];
            }
            else
            {
                lazy[index * 2 + 1] += val;
                lazy[index * 2 + 2] += val;
                seg[index] += (val * (high - low + 1));
                return seg[index];
            }
        }
        return seg[index] = rangeSumUpdateHelper(2 * index + 1, low, mid, l, r, val) +
                            rangeSumUpdateHelper(2 * index + 2, mid + 1, high, l, r, val);
    }

public:
    SegmentTreeSumWithLazyUpdates(vector<int> arr1)
    {
        seg = vector<int>(4 * arr1.size(), 0);
        lazy = vector<int>(4 * arr1.size(), 0);
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
    void rangeSumUpdate(int l, int r, int val)
    {
        rangeSumUpdateHelper(0, low, high, l, r, val);
    }
};
int main()
{
    // vector<int> arr = {10, 12, 3, 6, 3, 5, 9, 2, 5, 46};
    vector<int> arr = {2, 3, 1, 1, 5, 3};
    SegmentTreeSumWithLazyUpdates seg(arr);
    // cout << seg.rangeSum(0,5) << endl;
    // seg.rangeSumUpdate(0, 5, 10);
    // seg.rangeSumUpdate(3, 5, 5);
    cout << seg.rangeSum(2, 4) << endl;
    return 0;
}