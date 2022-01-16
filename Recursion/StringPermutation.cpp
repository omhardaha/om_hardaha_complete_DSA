#include <bits/stdc++.h>
using namespace std;

void powerSet(int index, string s, string temp)
{
  if (index == s.size())
  {
    cout << temp << endl;
    return;
  }
  temp += s[index];
  powerSet(index + 1, s, temp);
  temp.pop_back();
  powerSet(index + 1, s, temp);
}

void permutations(string s, int index = 0)
{
  if (index == s.size())
  {
    cout << s << endl;
    return;
  }
  for (int i = index; i < s.size(); i++)
  {
    swap(s[index], s[i]);

    permutations(s, index + 1);

    swap(s[index], s[i]);
  }
}


void letterPermutations(string& s, int index)
{
  
  if (index == s.size())
  {
      // ans.push_back(s);
      cout<<s<<endl;
    return;
  }
      
      if(isdigit(s[index]) ) letterPermutations(s,index+1);
      else {
        char c = s[index] ;
        s[index] = islower(s[index]) ? toupper(s[index]) :  tolower(s[index]);
        letterPermutations(s,index+1);
        s[index]=c;
        letterPermutations(s,index+1);
      }

};
int main()
{
  string s = "AAAAAAAAAAA";
  string temp;
     powerSet(0,s,temp);
  // permutations(s);

  // letterPermutations(s,0);

  // int k  = 2%3;

  // cout<<(6^6);
  return 0;
}