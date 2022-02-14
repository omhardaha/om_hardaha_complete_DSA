#include <bits/stdc++.h>
using namespace std;

vector<int> NGL(vector<int> nums)
{
    stack<int> temp;
    for (int i = 0; i <nums.size(); i++)
    {
        while (!temp.empty() && temp.top() <= nums[i])
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
    vector<int> nums = {10, 5, 11, 10, 20, 12 };
    vector<int> ans = NGL(nums);

    for (auto i : ans)
        cout << i << " ";
    return 0;
}