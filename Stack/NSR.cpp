#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/fab3dbbdce746976ba35c7b9b24afde40eae5a04/1/#
vector<int> NSR(vector<int> nums)
{
    stack<int> temp;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        while (!temp.empty() && temp.top() >= nums[i])
        {
            temp.pop();
        }
        // for pushing this element
        int p = nums[i];
        nums[i] = (temp.empty()) ? -1 : temp.top();
        temp.push(p);
    }

    return nums;
}

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
}


int main()
{
    vector<int> nums = {3, 8, 5, 2, 25};
    vector<int> ans = NSR(nums);
    vector<int> nsrI = NSRIndex(nums);

    for (auto i : ans)
        cout << i << " ";
    cout<<endl;
    for (auto i : nsrI)
        cout << i << " ";
    
    return 0;
}