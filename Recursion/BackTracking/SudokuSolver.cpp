#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>> &board, int row, int col, char c)
{
 // for every row and column
 for (int i = 0; i < 9; i++)
 {
  if (board[row][i] == c || board[i][col] == c)
  {
   return false;
  }
 }
 // for every 3x3 squre
 // findinding first element of square
 row -= (row % 3);
 col -= (col % 3);
 if (board[row][col] == c || board[row][col + 1] == c || board[row][col + 2] == c ||
     board[row + 1][col] == c || board[row + 1][col + 1] == c || board[row + 1][col + 2] == c ||
     board[row + 2][col] == c || board[row + 2][col + 1] == c || board[row + 2][col + 2] == c)
 {

  return false;
 }

 return true;
}

bool solve(vector<vector<char>> &board, int count)
{
 if (count == 13)
 {
  for (auto i : board)
  {
   for (auto k : i)
    cout << k << " ";
   cout << endl;
  }
  return;
 }
 for (int row = 0; row < 9; row++)
 {
  for (int col = 0; col < 9; col++)
  {
   if (board[row][col] == '.')
   {
    for (char temp = '1'; temp <= '9'; temp++)
    {
     if (isSafe(board, row, col, temp))
     {
      board[row][col] = temp;
      solve(board, count - 1);
      board[row][col] = '.';
     }
    }
   }
  }
 }
 return false;
}

int main()
{
 vector<vector<char>> board =
     {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
 int count = 0;
 for (auto i : board)
 {
  for (auto k : i)
   if (k == '.')
    count++;
 }
 cout << count << endl;
 // for(auto i:board){
 //  for(auto k:i) cout<<k << " ";
 //  cout<<endl;
 // }
 solve(board, count);
 // for (auto i : board)
 // {
 //  for (auto k : i)
 //   cout << k << " ";
 //  cout << endl;
 // }
 return 0;
}