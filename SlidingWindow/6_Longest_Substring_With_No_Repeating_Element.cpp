#include <bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1/#

int longestKSubstr(string s, int k)
{
    int ans = 0;

    int i = 0;
    int j = 0;
    unordered_map<char, int> p;

    while (j < s.size())
    {
        // remove front element if ans is greater
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
        // check ans
        if (p.size() == k)
        {
            ans = max(ans, j - i);
        }
        // add jth element to the answer
        if (p.size() <= k)
        {
            p[s[j]]++;
            j++;
        }
    }
    // check for last element
    if (p.size() == k)
    {
        ans = max(ans, j - i);
    }

    return ans;
}

int main()
{

    string s = "ababerebebebe";
    int ans = longestKSubstr(s, 3);
    cout << ans;
    return 0;
}