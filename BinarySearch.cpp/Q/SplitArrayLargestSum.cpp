#include <bits/stdc++.h>
using namespace std;
int SplitArrayLargestSums(vector<int> &nums, int parts)
{
    int low = INT_MIN; // 10
    int high = 0;      // 32
    for (auto i : nums)
    {
        high += i;         //
        low = max(low, i); //
    }
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        cout << "mid= " << mid << endl;
        int tempParts = 0;
        int temp = 0;
        for (auto i : nums)
        {
            if (temp + i > mid)
            {
                temp = i;
                tempParts++;
            }
            else
            {
                temp += i;
            }
        }
        if (temp > 0)
        {
            tempParts++;
        }
        cout << tempParts << endl;
        if (tempParts > parts)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return high;
}
int main()
{
    vector<int> nums = {7, 2, 5, 10, 8};
    // vector<int> nums = {1, 2, 3, 4, 5};
    int parts = 3;
    cout << SplitArrayLargestSums(nums, 2);
    return 0;
}