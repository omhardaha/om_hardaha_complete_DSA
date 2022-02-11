#include <bits/stdc++.h>
using namespace std;

int findKthSmallest(vector<int> &nums, int k)
{
    priority_queue<int> max_heap;
    for (auto i : nums)
    {
        max_heap.push(i);
        if (max_heap.size() > k)
            max_heap.pop();
    }
    return max_heap.top();
}
int main()
{
    // vector<int>nums = {1,4,3,2,5,6};
    // int k = 2;
    // cout<<findKthSmallest(nums,k);

    return 0;
}