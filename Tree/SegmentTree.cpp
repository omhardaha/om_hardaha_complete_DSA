#include <bits/stdc++.h>
using namespace std;
vector<int> seg(40, 0);
vector<int> arr = {10, 12, 3, 6, 3, 5, 9, 2, 5, 46};
void build(int i, int low, int high)
{
    if (low == high)
    {
        seg[low] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    build(i * 2 + 1, low, mid);
    build(i * 2 + 2, mid + 1, high);
    seg[i] = min(seg[i * 2 + 1], seg[i * 2 + 2]);
}
int rangeSum(int low, int high, int l, int r)
{
    int mid = (low + high) / 2;
        
}
int main()
{
    return 0;
}