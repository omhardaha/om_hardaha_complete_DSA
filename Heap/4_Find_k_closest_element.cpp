#include <bits/stdc++.h>
using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        priority_queue< pair<int,int> > max_heap;       
        
        for(auto i:arr){
         max_heap.push({abs(i-x),i});
        if(max_heap.size()>k) max_heap.pop();
        }
        
        while(!max_heap.empty()){
            ans.push_back(max_heap.top().second);
            max_heap.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
int main(){
    vector<int> t = {6,5,3,2,8,10,9};
    int k = 4;
    int x = 5;
   
//     vector<int> ans = findClosestElements(t,k,x);
// for(auto i:t) cout<<i<<" ";
// cout<<endl;
// for(auto i:ans) cout<<i<<" ";

unordered_map<int,int> o;
o[9] = 8;
for(auto i : o) cout<<i.first;

 return 0;
}