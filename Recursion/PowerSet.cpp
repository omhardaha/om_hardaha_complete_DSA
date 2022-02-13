#include <bits/stdc++.h>
using namespace std;
void powerSet(int index, string s, string temp, vector<string> &ans)
{
    if (index == s.size())
    {
        ans.push_back(temp);
        return;
    }
    temp += s[index];
    powerSet(index + 1, s, temp, ans);
    temp.pop_back();
    powerSet(index + 1, s, temp, ans);
}

int main()
{

    string s = "abc";
    string temp = "";

    vector<string> ans;

    powerSet(0, s, temp, ans);

    for (auto i : ans)
        cout << i << " ";
    return 0;
}