#include <bits/stdc++.h>
using namespace std;
class SegmentTreeMin
{
    vector<int> arr;
    vector<int> seg;
    int low = 0;
    int high = 0;

private:
    int build(int i, int low, int high)
    {
        if (low == high)
        {
            return seg[i] = arr[low];
        }
        int mid = (low + high) / 2;
        return seg[i] = min(build(i * 2 + 1, low, mid), build(i * 2 + 2, mid + 1, high));
    }

public:
    SegmentTreeMin(vector<int> arr1)
    {
        seg = vector<int>(4 * arr1.size(), INT_MAX);
        arr = arr1;
        high = arr1.size() - 1;
        build(0, low, high);
    }
    int rangMinHelper(int i, int low, int high, int l, int r)
    {
        if (low >= l && high <= r)
        {
            return seg[i];
        }
        if (high < l || low > r)
        {
            return INT_MAX;
        }
        int mid = (low + high) / 2;
        return min(rangMinHelper(i * 2 + 1, low, mid, l, r), rangMinHelper(i * 2 + 2, mid + 1, high, l, r));
    }
    int rangMin(int l, int r)
    {
        return rangMinHelper(0, low, high, l, r);
    }
};
int main()
{
    vector<int> arr = {10, 12, 3, 6, 3, 5, 9, 2, 5, 46};
    SegmentTreeMin seg(arr);
    cout << seg.rangMin(7, 9);
    return 0;
}