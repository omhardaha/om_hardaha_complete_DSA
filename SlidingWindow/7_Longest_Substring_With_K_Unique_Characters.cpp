#include <bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1/#

int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int i = 0;
        int j = 0;
        short int count = 0;
        unordered_map<char, int> p;
         
    while (j < s.size())
    {
        p[s[j]]++;
    
        if(p[s[j]]>1) count++;
            
            while (count > 0)
            {
                p[ s[i] ]--;
                if (p[s[i]] == 1)
                {
                    count--;
                }
                i++;
            }
            j++;
        // check ans
        ans = max(ans, j - i);
        }
    return ans;
    }

int main()
{

    string s = "ababerebebebe";
    int ans = lengthOfLongestSubstring(s);
    cout << ans;
    return 0;
}