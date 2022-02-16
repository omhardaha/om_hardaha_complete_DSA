#include <bits/stdc++.h>
using namespace std;
int KnapSack(int W, int wt[], int val[], int n, vector<vector<int>> &dp)
{
  if (n == -1 || W == 0)
    return 0;

  if (dp[n][W] != -1)
    return dp[n][W];

  if (wt[n] <= W) // if weigth is lesser or equal we can take it and not take it 2 options
  {
    return dp[n][W] = max(val[n] + KnapSack(W - wt[n], wt, val, n - 1, dp), KnapSack(W, wt, val, n - 1, dp));
  }
  return dp[n][W] = KnapSack(W, wt, val, n - 1, dp); // if weigth is greater we can not take it
}

int main()
{
  int n = 3;
  int w = 4;
  int wt[] = {1, 2, 3};
  int val[] = {4, 5, 1};
  vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));

  cout<< KnapSack(w, wt, val, n - 1, dp);
  return 0;
}