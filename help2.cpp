#include <bits/stdc++.h>
using namespace std;
int floorNumberv(vector<int> a, int val)
{
    if (a[0] > val)
        return -1; // bcz no ceiling present
    int low = 0;
    int high = a.size() - 1;

    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int ans = -1;
        if (a[mid] == val)
        {
            ans = mid;
            low = mid + 1;
        }
        else if (val > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (ans != -1)
    {
        return ans;
    }
    return high; // if val not found
}
int main()
{
    vector<int> arr = {3, 4, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 8, 10, 13};
    cout << floorNumberv(arr, 6);
    return 0;
}