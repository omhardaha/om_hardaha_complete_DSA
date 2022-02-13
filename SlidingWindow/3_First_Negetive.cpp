#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1/#
vector<int> firstNegetive(vector<int> &nums, int k)
{
    vector<int> ans;

    int n = 0;
    while (n < nums.size() && nums[n] > 0)
        n++;

    for (int i = 0; i < nums.size(); i++)
    {

        if (i >= k - 1)
        {
            if (n <= i)
                ans.push_back(nums[n]);
            if (n <= i - k + 1)
            {
                n++;
                while (n < nums.size() && nums[n] > 0)
                    n++;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> t = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> ans = firstNegetive(t, 4);

    for (auto i : t)
        cout << i << " ";
    cout << endl;

    for (auto i : ans)
        cout << i << " ";

    return 0;
}