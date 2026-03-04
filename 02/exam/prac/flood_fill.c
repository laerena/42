#include "flood_fill.h"

void fill(char **tab, t_point size, char target, int row, int col)
{
    if (row < 0 || col < 0 || row >= size.x || col >= size.y)
        return ;
    if (tab[row][col] != target)
        return ;
    tab[row][col] = 'F';
    fill(tab, size, target, row - 1, col);
    fill(tab, size, target, row + 1, col);
    fill(tab, size, target, row, col - 1);
    fill(tab, size, target, row, col + 1);
}

void flood_fill(char **tab, t_point size, t_point begin)
{
    char target = tab[begin.x][begin.y];
    fill(tab, size, target, begin.x, begin.y);
}