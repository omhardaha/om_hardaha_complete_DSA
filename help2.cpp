#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void setZeroes(vector<vector<int>> &grid)
    {
        bool row0 = false;
        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[0].size(); col++)
            {
                if (grid[row][col] == 0)
                {
                    grid[0][col] = 0;
                    if (row == 0)
                    {
                        row0 = true;
                    }
                    else
                    {
                        grid[row][0] = 0;
                    }
                }
            }
        }

        for (int col = 1; col < grid[0].size(); col++)
        {
            if (grid[0][col] == 0)
            {
                for (int row = 0; row < grid.size(); row++)
                {
                    grid[row][col] = 0;
                }
            }
        }
        for (int row = 1; row < grid.size(); row++)
        {
            if (grid[row][0] == 0)
            {
                for (int col = 0; col < grid[0].size(); col++)
                {
                    grid[row][col] = 0;
                }
            }
        }
        if (grid[0][0] == 0)
        {
            for (int row = 0; row < grid.size(); row++)
            {
                grid[row][0] = 0;
            }
        }
        if (row0)
        {
            for (int col = 0; col < grid[0].size(); col++)
            {
                grid[0][col] = 0;
            }
        }
    }
};
int main()
{

    return 0;
}