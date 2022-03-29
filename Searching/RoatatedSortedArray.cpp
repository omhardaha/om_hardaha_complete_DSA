#include <bits/stdc++.h>
using namespace std;
int getPivot(vector<int> arr, int l, int r)
{
    if (arr.empty() || arr[0] < arr[arr.size() - 1])
    {
        return -1;
    }
    if (arr.size() > 1)
    {
        if (arr[0] > arr[1])
        {
            return 0;
        }
    }
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        if (arr[mid] < arr[r])
        {
            if (arr[r] > arr[r - 1] && arr[r] > arr[r + 1])
            {
                return r;
            }
            r = mid - 1;
        }
        else
        {
            l = mid;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;
    cout << getPivot(arr, 0, arr.size() - 1);
    return 0;
}