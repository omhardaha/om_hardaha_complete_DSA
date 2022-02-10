#include <bits/stdc++.h>
using namespace std;

 vector<int> Sort_KSorted_Array(vector<int>& nums, int k) {

    priority_queue<int , vector<int >, greater<int> > min_heap ;
    vector<int>ans;

    for(int right = 0;right<k && right<nums.size();right++){
min_heap.push(nums[right]);
    }

   for(int i = k ;i<nums.size();i++){
       min_heap.push(nums[i]);
       ans.push_back(min_heap.top());
       min_heap.pop();
   }
//    cout<<min_heap.size();
   while (!min_heap.empty())
   {
       ans.push_back(min_heap.top());
       min_heap.pop();
   }

   return ans;
}
int main(){
    vector<int> t = {6,5,3,2,8,10,9};
    int k = 8;
   
    vector<int> ans = Sort_KSorted_Array(t,k);
for(auto i:t) cout<<i<<" ";
cout<<endl;
for(auto i:ans) cout<<i<<" ";
 return 0;
}