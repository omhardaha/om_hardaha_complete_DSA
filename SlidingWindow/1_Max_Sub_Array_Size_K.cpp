#include <bits/stdc++.h>
using namespace std;

int maxSlidingWindow(vector<int> &nums, int k)
{
    int ans = INT_MIN;
    int curSum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
     curSum+=nums[i];
       if(i>=k-1){
           ans = max(ans , curSum);
           curSum-=nums[i-k+1];
       }
    }

    return ans;
}

int main()
{
    // vector<int> t = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> t = {1, 3, 551, -3, 5, 3, 6, 700};
    int k = 1;
    int ans = maxSlidingWindow(t, k);

    for (auto i : t)
        cout << i << " ";
    cout << endl;
    
        cout << ans << " ";

    return 0;
}