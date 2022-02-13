#include <bits/stdc++.h>
using namespace std;

void letterPermutations(string& s, vector<string>& ans, int index=0)
{
  
  if (index == s.size())
  {
      // ans.push_back(s);
      cout<<s<<endl;
    return;
  }
      
      if(isdigit(s[index]) ) letterPermutations(s,ans,index+1);
      else {
        char c = s[index] ;
        s[index] = islower(s[index]) ? toupper(s[index]) :  tolower(s[index]);
        letterPermutations(s,ans,index+1);
        s[index]=c;
        letterPermutations(s,ans,index+1);
      }
};
int main()
{
   string s = "a3Lbc";

    vector<string> ans;

    letterPermutations(s,ans);

    for (auto i : ans)
        cout << i << " ";
    return 0;
}