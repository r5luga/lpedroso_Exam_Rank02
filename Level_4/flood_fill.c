#include "ft_flood_fill.h"

static void ft_fill(char **tab, t_point size, int x, int y, char target)
{
    if (x < 0 || x >= size.x || y < 0 || y >= size.y)
        return;

    if (tab[y][x] != target)
        return;

    tab[y][x] = 'F';

    ft_fill(tab, size, x + 1, y,     target);
    ft_fill(tab, size, x - 1, y,     target);
    ft_fill(tab, size, x,     y + 1, target);
    ft_fill(tab, size, x,     y - 1, target);
}

void ft_flood_fill(char **tab, t_point size, t_point begin)
{
    char target = tab[begin.y][begin.x];
    ft_fill(tab, size, begin.x, begin.y, target);
}
/*
#include "ft_flood_fill.h"

void ft_flood_fill(char **tab, t_point size, t_point begin)
{
    char target = tab[begin.y][begin.x];

    if (begin.x < 0 || begin.x >= size.x || begin.y < 0 || begin.y >= size.y)
        return;

    if (tab[begin.y][begin.x] != target)
        return;

    tab[begin.y][begin.x] = 'F';

    ft_flood_fill(tab, size, (t_point){begin.x + 1, begin.y});
    ft_flood_fill(tab, size, (t_point){begin.x - 1, begin.y});
    ft_flood_fill(tab, size, (t_point){begin.x, begin.y + 1});
    ft_flood_fill(tab, size, (t_point){begin.x, begin.y - 1});
}
*/
