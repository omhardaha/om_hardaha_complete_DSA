#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1/#

int longestKSubstr(string s, int k)
{
    int ans = -1;
    int i = 0;
    int j = 0;
    unordered_map<char, int> p;

    while (j < s.size())
    {
        if (p.size() > k)
        {
            while (p.size() > k)
            {
                p[s[i]]--;
                if (p[s[i]] == 0)
                {
                    p.erase(s[i]);
                }
                i++;
            }
        }

        if (p.size() == k)
        {
            ans = max(ans, j - i);
        }
        if (p.size() <= k)
        {
            p[s[j]]++;
            j++;
        }
    }
    if (p.size() == k)
    {
        ans = max(ans, j - i);
    }

    return ans;
}

int main()
{

    string s = "ababerebebebe";
    int k =3;
    int ans = longestKSubstr(s,3);
    cout << ans;
    return 0;
}