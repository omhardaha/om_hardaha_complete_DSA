#include <bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/smallest-number-on-left3403/1/
vector<int> NSL(vector<int> nums)
{
    stack<int> temp;
    for (int i = 0; i <nums.size(); i++)
    {
        while (!temp.empty() && temp.top() >= nums[i])
        {
            temp.pop();
        }
        // for pushing this element
        int p = nums[i];

        if (temp.empty())
            nums[i] = -1;
        else
            nums[i] = temp.top();

        temp.push(p);
    }

    return nums;
}
int main()
{
    vector<int> nums = {3, 8, 5, 2, 25};
    vector<int> ans = NSL(nums);

    for (auto i : ans)
        cout << i << " ";
    return 0;
}