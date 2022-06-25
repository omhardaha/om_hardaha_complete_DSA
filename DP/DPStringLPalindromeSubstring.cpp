#include <bits/stdc++.h>
using namespace std;
string longestPalindrome(string text)
{
    vector<vector<int>> dp(text.size(), vector<int>(text.size(), 1));

    int ans = 0, start = 0, end = 0;

    for (int col = 1; col < dp.size(); col++)
    {
        int i = 0;
        int j = col;
        while (j < text.size())
        {
            if (text[i] == text[j] && dp[i + 1][j - 1] == 1)
            {
                dp[i][j] = 1;
                if (ans < j - i + 1)
                {
                    ans = j - i + 1;
                    start = i;
                    end = j;
                }
            }
            else
            {
                dp[i][j] = 0;
            }
            i++;
            j++;
        }
    }
    return text.substr(start, end - start + 1);
}

int main()
{

    string text1 = "abcde";
    cout << longestPalindrome(text1);
    return 0;
}