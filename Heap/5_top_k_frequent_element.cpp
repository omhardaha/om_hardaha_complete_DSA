#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        
        unordered_map<int,int> temp;
        for(int i :nums) temp[i]++;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>min_heap;
        
        for(auto i:temp){
            min_heap.push({i.second,i.first});
            if(min_heap.size() > k) min_heap.pop();
        }
        
        while(!min_heap.empty()){
            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return ans;
    }
int main(){
    vector<int> t = {6,5,6,6,5,6,6,6,9};
    int k = 2;
   
    vector<int> ans = topKFrequent(t,k);
for(auto i:t) cout<<i<<" ";
cout<<endl;
for(auto i:ans) cout<<i<<" ";

 return 0;
}