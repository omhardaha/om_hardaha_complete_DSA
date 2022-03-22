#include <bits/stdc++.h>
using namespace std;
bool check(vector<vector<int>> &image, int i, int j, int pcolor)
{
    if (i - 1 >= 0)
    {
        if (image[i - 1][j] == pcolor)
        {
            return true;
        }
    }
    if (j - 1 >= 0)
    {
        if (image[i][j - 1] == pcolor)
        {
            return true;
        }
    }
    if (i + 1 < image.size())
    {
        if (image[i + 1][j] == pcolor)
        {
            return true;
        }
    }
    if (j + 1 < image[0].size())
    {
        if (image[i][j + 1] == pcolor)
        {
            return true;
        }
    }
    return false;
}

void printColor(vector<vector<int>> &image, int i, int j, int newColor)
{
    if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != 4 || check(image, i, j, newColor))
    {
        return;
    }
    image[i][j] = newColor;
    int printinColor = (newColor == 1) ? 2 : 1;
    printColor(image, i + 1, j, printinColor);
    printColor(image, i - 1, j, printinColor);
    printColor(image, i, j + 1, printinColor);
    printColor(image, i, j - 1, printinColor);
}
void printColor2(vector<vector<int>> &image, int i, int j, int newColor)
{
    if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != 0 || check(image, i, j, newColor))
    {
        return;
    }
    image[i][j] = newColor;
    int printinColor = (newColor == 4) ? 3 : 4;
    printColor(image, i + 1, j, printinColor);
    printColor(image, i - 1, j, printinColor);
    printColor(image, i, j + 1, printinColor);
    printColor(image, i, j - 1, printinColor);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int row, col;
        cin >> row >> col;
        vector<vector<int>> matrix(row, vector<int>(col, 4));
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        matrix[x1 - 1][y1 - 1] = 1;
        matrix[x2 - 1][y2 - 1] = 2;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                if (matrix[i][j] == 4)
                {
                    printColor(matrix, i, j, 1);
                    if (matrix[i][j] == 4)
                    {
                        printColor(matrix, i, j, 2);
                    }
                }
            }
        }
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                if (matrix[i][j] == 4)
                {
                    printColor2(matrix, i, j, 2);
                }
            }
        }

        for (auto r : matrix)
        {
            for (auto item : r)
            {
                cout << item << " ";
            }
            cout << endl;
        }
    }
    return 0;
}