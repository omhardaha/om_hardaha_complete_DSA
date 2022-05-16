#include <bits/stdc++.h>
using namespace std;

// Longest Common Subsequence Related Qs -
// https://leetcode.com/problems/longest-common-subsequence/
// https://leetcode.com/problems/longest-palindromic-subsequence/
//  https://leetcode.com/problems/longest-palindromic-subsequence/
// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
// https://leetcode.com/problems/shortest-common-supersequence/
// https://leetcode.com/problems/distinct-subsequences/
// https://leetcode.com/problems/wildcard-matching/
// https://leetcode.com/problems/edit-distance/
// https://leetcode.com/problems/delete-operation-for-two-strings
// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings
// https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/
// https://leetcode.com/problems/longest-increasing-subsequence/

int solve(string &text1, string &text2, vector<vector<int>> &dp, int i, int j)
{
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (text1[i] == text2[j])
        return dp[i][j] = 1 + solve(text1, text2, dp, i - 1, j - 1);

    int left = solve(text1, text2, dp, i - 1, j);
    int right = solve(text1, text2, dp, i, j - 1);
    return dp[i][j] = max(left, right);
}

int longestCommonSubsequenceMemo(string text1, string text2)
{
    vector<vector<int>> dp(text1.size() + 3, vector<int>(text2.size() + 3, -1));
    return solve(text1, text2, dp, text1.size() - 1, text2.size() - 1);
}

int longestCommonSubsequenceTab(string text1, string text2)
{
    vector<vector<int>> grid(text1.size() + 1, vector<int>(text2.size() + 1, 0));
    for (int i = text1.size() - 1; i >= 0; i--)
    {
        for (int j = text2.size() - 1; j >= 0; j--)
        {
            if (text1[i] == text2[j])
            {
                grid[i][j] = 1 + grid[i + 1][j + 1];
                continue;
            }
            int left = grid[i][j + 1];
            int right = grid[i + 1][j];
            grid[i][j] = max(left, right);
        }
    }
    return grid[0][0];
}

string printLCS(string text1, string text2)
{
    vector<vector<int>> grid(text1.size() + 1, vector<int>(text2.size() + 1, 0));
    for (int i = text1.size() - 1; i >= 0; i--)
    {
        for (int j = text2.size() - 1; j >= 0; j--)
        {
            if (text1[i] == text2[j])
            {
                grid[i][j] = 1 + grid[i + 1][j + 1];
                continue;
            }
            int left = grid[i][j + 1];
            int right = grid[i + 1][j];
            grid[i][j] = max(left, right);
        }
    }

    // PRINT COMMON STRING
    int length = grid[0][0];
    string printLCS;
    int r = 0;
    int c = 0;
    while (length)
    {
        if (text1[r] == text2[c])
        {
            length--;
            printLCS += text1[r];
            r++;
            c++;
        }
        else
        {
            if (grid[r + 1][c] >= grid[r][c + 1])
            {
                r++;
            }
            else
            {
                c++;
            }
        }
    }
    return printLCS;
}

int main()
{
    string text1 = "abcde", text2 = "ace";
    cout << printLCS(text1, text2);
    return 0;
}