#include <bits/stdc++.h>
using namespace std;
// similar Questions
//https://leetcode.com/problems/find-all-anagrams-in-a-string/
//https://leetcode.com/problems/permutation-in-string/submissions/
// easy - https://leetcode.com/problems/valid-anagram/submissions/

//try - https://leetcode.com/problems/group-anagrams/
vector<int> findAnagrams(string s, string p)
{
    vector<int> ans;
    unordered_map<char, int> anagram;

    for (char i : p)
        anagram[i]++;
    int count = anagram.size();
    int k = p.size();

    for (int i = 0; i < s.size(); i++)
    {
        if (i >= k)
        {
            if (anagram.find(s[i - k]) != anagram.end())
            {
                anagram[s[i - k]]++;
                if (anagram[s[i - k]] == 1)
                {
                    count++;
                }
            }
        }
        if (anagram.find(s[i]) != anagram.end())
        {
            anagram[s[i]]--;
            if (anagram[s[i]] == 0)
            {
                count--;
            }
        }
        if (count == 0)
        {
            ans.push_back(i - k + 1);
        }
    }

    return ans;
}
int main()
{

    string s = "cbaebabacd", p = "abc";
    vector<int> ans = findAnagrams(s, p);

    for (auto i : ans)
        cout << i << " ";
    return 0;
}