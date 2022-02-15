#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-window-substring

string minWindow(string s, string t)
{
    unordered_map<char, int> p;
    for (char i : t)
        p[i]++;
    int count = p.size();

    int low = 0;
    int high = 0;
    int minL = INT_MAX;

    int i = 0;
    int j = 0;

    while (j < s.size())
    {
        if (p.find(s[j]) != p.end())
        {
            p[s[j]]--;
            if (p[s[j]] == 0)
                count--;
            j++;
        }
        else
        {
            j++;
        }

        while (count == 0)
        {
            if (j - i < minL)
            {
                minL = j - i;
                low = i;
                high = j;
            }
            if (p.find(s[i]) != p.end())
            {
                p[s[i]]++;
                if (p[s[i]] > 0)
                {
                    count++;
                }
                i++;
            }
            else
            {
                i++;
            }
        }
    }
    return s.substr(low, high - low);
}

int main()
{
    string s = "ADOBECODEBANC", t = "ABC";
    cout << minWindow(s, t);
    return 0;
}