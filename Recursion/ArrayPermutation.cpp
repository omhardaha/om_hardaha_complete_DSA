#include <bits/stdc++.h>
using namespace std;

void permutations(vector<int> &s, vector<vector<int>> &ans, int index = 0)
{
  if (index == s.size())
  {
    ans.push_back(s);
    return;
  }
  for (int i = index; i < s.size(); i++)
  {
    swap(s[index], s[i]);
    permutations(s, ans, index + 1);
    swap(s[index], s[i]);
  }
}

int main()
{
  vector<int> nums = {1, 17, 8, 3};
  vector<vector<int>> ans;
  permutations(nums, ans);
  for (auto t : ans)
  {
    for (auto i : t)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}