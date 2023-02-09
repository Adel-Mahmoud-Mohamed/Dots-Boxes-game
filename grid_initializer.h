#ifndef GRID_INITIALIZER_H_INCLUDED
#define GRID_INITIALIZER_H_INCLUDED



void Grid_initializer(int n, char grid[3 * n + 2][5 * n + 2])
{
    char dot = 254;
    for (int i = 0; i < (3 * n + 2); i++)
    {
        for (int j = 0; j < (5 * n + 2); j++)
        {
            if (i == 0)
            {
                if (j == 0) grid[i][j] = ' ';
                else if ((j + 4) % 5 == 0) grid[i][j] = ((j + 4) / 5) + 48;
                else grid[i][j] = ' ';
            }
            else if ((i + 2) % 3 == 0)
            {
                if (j == 0) grid[i][j] = ((i + 2) / 3) + 48;
                else if ((j + 4) % 5 == 0) grid[i][j] = dot;
                else grid[i][j] = ' ';
            }
            else grid[i][j] = ' ';
        }
    }
}


#endif // GRID_INITIALIZER_H_INCLUDED
