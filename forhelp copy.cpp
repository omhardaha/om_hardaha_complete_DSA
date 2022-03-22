#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int row, col, x1, x2, y1, y2;
        cin >> row >> col;
        vector<vector<int>> matrix(row, vector<int>(col, 0));
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        x2--;
        y1--;
        y2--;
        // if they not dig
        if (((x1 + y1) % 2) != ((x2 + y2) % 2))
        {
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    int t = (i + j) % 2;
                    if (t == (x1 + y1) % 2)
                    {
                        cout << 1 << " ";
                    }
                    else
                    {
                        cout << 2 << " ";
                    }
                }
                cout << endl;
            }
            continue;
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int t = (i + j) % 2;
                if (t == (x1 + y1) % 2)
                {
                    matrix[i][j] = 1;
                }
                else
                {
                    matrix[i][j] = 2;
                }
            }
        }
        matrix[x1][y1] = 1;
        matrix[x2][y2] = 2;
        if (x2 > 0)
        {
            matrix[x2 - 1][y2] = 4;
        }
        if (x2 < row - 1)
        {
            matrix[x2 + 1][y2] = 4;
        }
        if (y2 > 0)
        {
            matrix[x2][y2 - 1] = 4;
        }
        if (y2 < col - 1)
        {
            matrix[x2][y2 + 1] = 4;
        }
        for (auto rr : matrix)
        {
            for (auto item : rr)
            {
                cout << item << " ";
            }
            cout << endl;
        }
    }
    return 0;
};