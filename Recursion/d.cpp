#include <bits/stdc++.h>
using namespace std;
 void powerSet(int index, string s, string temp,vector<string>&ans,unordered_set<string>&tempAns)
{
  if (index == s.size())
  {
      
          cout<<temp<<endl;
    //   if(temp.size()==10){
    //       cout<<"debug1";
    //       if(tempAns.find(temp) ==tempAns.end())tempAns.insert(temp);
    //       else ans.push_back(temp);
    //   }
    return;
  }
  temp += s[index];
  powerSet(index + 1, s, temp,ans,tempAns);
  temp.pop_back();
  powerSet(index + 1, s, temp,ans,tempAns);
}
int main(){
   vector<string>ans;
        unordered_set<string>temp;
        string s="AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
        // string s="ABCD";
        string t="";
        powerSet(0,s,t,ans,temp);
        for(auto i:ans){
            cout<<i<<endl;
        }
 return 0;
}