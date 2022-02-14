#include <bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1/#
//https://leetcode.com/problems/fruit-into-baskets/

int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int i = 0;
        int j = 0;
        unordered_map<char, int> p;
         
    while (j < s.size())
    {
        p[s[j]]++;
        j++;
        
        //if window size (j-i) is == p.size() then it means it is the  the lengthOfLongestSubstring (every character is distinct)
            
            while (p.size() != j-i )
            {
                p[ s[i] ]--;
                if ( p[s[i]] == 0)
                {
                    p.erase(s[i]);
                }
                i++;
            }
        // check ans
        ans = max(ans, j-i); //j-1 is the updated window size
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