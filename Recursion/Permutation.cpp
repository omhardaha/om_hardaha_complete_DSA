#include <bits/stdc++.h>
using namespace std;

void permutations(string s, vector<string> &ans, int index = 0)
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

  string s = "abcd";
  string temp = "";

  vector<string> ans;

  permutations(s, ans); // number of permutation = factorial n

  for (auto i : ans)
    cout << i << " ";
  return 0;
}