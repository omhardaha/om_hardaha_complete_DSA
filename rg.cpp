#include <bits/stdc++.h>
using namespace std;

bool cross(vector<int>& stones,int i,int k){
        if(i==stones.size()-1){
        // if(stones[i]-stones[i-1] != k)return false;
            return true;
        }        
        if(stones[i]-stones[i-1] != k)return false;
        
        if(cross(stones,i+1,k-1))return true;
        
        if(cross(stones,i+1,k))return true;

        if(cross(stones,i+1,k+1))return true;
        return false;
    }

int main(){
  // vector<int> m = {0,1,3,5,6,8,12,17};
  //  cout<<cross(m,1,1);
  // auto it = lower_bound(m.begin(),m.end(),112);
  
  // cout<<it-m.begin() ;
  // cout<< (it==m.end()) ;
  bool m = NULL;
  cout<<m;
 return 0;
}