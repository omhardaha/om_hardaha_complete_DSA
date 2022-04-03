#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<string> &NQueens, int r, int c)
{
 // for upper row
 for (int i = r; i >= 0; i--)
 
 {
  if (NQueens[i][c] == 'Q')
   return false;
 }

 // for left diagonal
 for (int row = r, col = c; row >= 0 && col >= 0; row--, col--)
 {
  if (NQueens[row][col] == 'Q')
   return false;
 }

 // for right diagonal
 for (int row = r, col = c; row >= 0 && col < NQueens[0].size(); row--, col++)
 {
  if (NQueens[row][col] == 'Q')
   return false;
 }
 return true;
}

int putQueens(vector<string> &NQueens, int i)
{
 if (i == NQueens.size())
 {
  for (auto k : NQueens)
  {
   for (auto i : k)
   {
    cout << i << "";
   }
   cout << endl;
  }
  cout << endl;

  return 1;
 }

 for (int k = 0; k < NQueens[0].size(); k++)
 {
  if (isSafe(NQueens, i, k))
  {
   NQueens[i][k] = 'Q';
   putQueens(NQueens, i + 1);
  }
  NQueens[i][k] = '.';
 }
 return 9;
}

int main()
{
 int n = 4;
 vector<string> NQueens = {
     ".....",
     ".....",
     ".....",
     ".....",
     "....."};
 putQueens(NQueens, 0);
 return 0;
}