#include <stdio.h>
#include <iostream>
#include <vector>

#include "CTimeStat.h"

using namespace std;


class CLandPerimeter {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ret = 0;
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int Lands = 0;

        if (1 == ROWS && 1 == COLS)
        {
            if (grid[0][0] == 1) return 4;
            else return 0;
        }
        else if (1 == ROWS && COLS > 1)
        {
            for (int i = 0; i < COLS; i++)
            {
                if (grid[0][i] == 1) Lands++;
            }
            return Lands * 4 - (Lands - 1) * 2;
        }
        else if (ROWS > 1 && COLS == 1)
        {
            for (int i = 0; i < ROWS; i++)
            {
                if (grid[i][0] == 1) Lands++;
            }
            return Lands * 4 - (Lands - 1) * 2;
        }
        
        ret = 0;
        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                if (1 == grid[r][c])
                {
                    Lands++;
                    ret += 4;
                    if (0 == r )
                    {
                        if (grid[r + 1][c] == 1) ret--;
                        if (c == 0 || c == COLS - 1)
                        {
                            if (grid[r][c == 0 ? c + 1 : c - 1] == 1) ret--;
                        }
                        else
                        {
                            if (grid[r][c - 1] == 1) ret--;
                            if (grid[r][c + 1] == 1) ret--;
                        }
                    }
                    else if (ROWS - 1 == r)
                    {
                        if (grid[r - 1][c] == 1) ret--;
                        if (c == 0 || c == COLS - 1)
                        {
                            if (grid[r][c == 0 ? c + 1 : c - 1] == 1) ret--;
                        }
                        else
                        {
                            if (grid[r][c - 1] == 1) ret--;
                            if (grid[r][c + 1] == 1) ret--;
                        }
                    }
                    else
                    {
                        if (grid[r + 1][c] == 1) ret--;
                        if (grid[r - 1][c] == 1) ret--;
                        if (c == 0 || c == COLS - 1)
                        {
                            if (grid[r][c == 0 ? c + 1 : c - 1] == 1) ret--;
                        }
                        else
                        {
                            if (grid[r][c - 1] == 1) ret--;
                            if (grid[r][c + 1] == 1) ret--;
                        }
                    }
                }
            }
        }

        return ret;
    }
};

void testLandPerimeter()
{
    CLandPerimeter c;
    vector<vector<int>> grid = { {0, 1, 0, 0},{1, 1, 1, 0},{0, 1, 0, 0},{1, 1, 0, 0} };
    cout << c.islandPerimeter(grid) << endl;
}