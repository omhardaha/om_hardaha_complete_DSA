#include <bits/stdc++.h>
using namespace std;
vector<int> NGRIndex(vector<int> nums)
{
    vector<int> ans(nums.size());
    stack<int> temp;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        while (!temp.empty() && nums[temp.top()] <= nums[i])
            temp.pop();
        ans[i] = temp.empty() ? -1 : temp.top();
        temp.push(i);
    }
    return ans;
};
vector<int> NSRIndex(vector<int> nums)
{
    vector<int> ans(nums.size());
    stack<int> temp;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        while (!temp.empty() && nums[temp.top()] >= nums[i])
            temp.pop();
        ans[i] = temp.empty() ? -1 : temp.top();
        temp.push(i);
    }
    return ans;
};
bool find132pattern(vector<int> &nums)
{
    vector<int> NGR = NGRIndex(nums);
    vector<int> NSR = NSRIndex(nums);
    for (auto i : nums)
        cout << i << " ";
    cout << endl;
    for (auto i : NGR)
        cout << i << " ";
    cout << endl;
    for (auto i : NSR)
        cout << i << " ";
    for (int i = 0; i < nums.size() - 2; i++)
    {
        if (NGR[i] != -1 && nums[i] < nums[NGR[i]] && NSR[NGR[i]] != -1 && nums[NSR[NGR[i]]] > nums[i] && nums[NSR[NGR[i]]] < nums[NGR[i]])
        {
            return true;
        }
    }
    return false;
}
int main()
{
    vector<int> nums = {1,0,1,-4,-3};
    cout << find132pattern(nums);
    return 0;
}