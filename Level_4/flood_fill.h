#ifndef FLOOD_FILL_H
# define FLOOD_FILL_H

typedef struct s_point
{
    int x; // horizontal
    int y; // vertical
}   t_point;

void ft_flood_fill(char **tab, t_point size, t_point begin);

#endif
