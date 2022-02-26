#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/generate-parentheses/
void genarate(vector<string> &ans, string s, int open, int close)
{
 if (open == 0 && close == 0)
 {
  ans.push_back(s);
  return;
 }

if(open<0 || close <0)return;
 genarate(ans, s + "(", open - 1, close);

 if (open < close)
  genarate(ans, s + ")", open, close - 1);
}

int main()
{
 vector<string> ans;
 int n = 4;
 genarate(ans, "", n, n);
 for (auto i : ans)
  cout << i << "      ";
 return 0;
}