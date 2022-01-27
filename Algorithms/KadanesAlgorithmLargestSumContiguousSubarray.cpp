#include <bits/stdc++.h>
using namespace std;

int MaxSumContiguousSubarray(vector<int> a)
{
    int maxSum = a[0];
    int curSum = a[0];
    for (int i = 1; i < a.size(); i++)
    {
        curSum += a[i];

        if (curSum < 0)
        {
            curSum = 0; // bcoz if -ve's found previous sum is not helpful
        }

        maxSum = max(maxSum, curSum);
    }
    return maxSum;
}

int main()
{
    vector<int> a = {12, -24, -7, 3, -9, 2, -52, 6, 9};
    cout << MaxSumContiguousSubarray(a);
    return 0;
}