#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for (auto i : nums)
    {
        min_heap.push(i);
        if (min_heap.size() > k)
            min_heap.pop();
    }
    return min_heap.top();
}
int main()
{
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 2;
    cout << findKthLargest(nums, k);
    return 0;
}