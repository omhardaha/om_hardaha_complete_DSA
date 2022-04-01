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

bool solve(vector<vector<char>> &board)
{
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
                        if (solve(board))
                        {
                            return true;
                        }
                        else
                        {
                            board[row][col] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
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
    solve(board);
    for (auto row : board)
    {
        for (auto item : row)
        {
            cout << item << " ";
        }
        cout << endl;
    }
    return 0;
}