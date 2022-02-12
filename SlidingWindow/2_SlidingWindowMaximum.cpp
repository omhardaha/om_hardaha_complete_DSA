#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> buffer;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {

        while (!buffer.empty() && buffer.front() < nums[i])
            buffer.pop_front();

        if (buffer.empty() || nums[i] >= buffer.back())
            buffer.push_back(nums[i]);

        else
            buffer.push_front(nums[i]);

        if (i >= k - 1)
        {
            ans.push_back(buffer.back());
            if (buffer.back() == nums[i - k + 1])
                buffer.pop_back();
        }
    }
    return ans;
}

int main()
{
    vector<int> t = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(t, k);

    for (auto i : t)
        cout << i << " ";
    cout << endl;

    for (auto i : ans)
        cout << i << " ";

    return 0;
}