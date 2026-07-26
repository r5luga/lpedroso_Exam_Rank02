#include <unistd.h>
#include "ft_flood_fill.h"

static void ft_print_map(char **tab, t_point size)
{
    int y, x;

    y = 0;
    while (y < size.y)
    {
        x = 0;
        while (x < size.x)
        {
            write(1, &tab[y][x], 1);
            x++;
        }
        write(1, "\n", 1);
        y++;
    }
}

int main(void)
{
    char map0[] = "000000";
    char map1[] = "011110";
    char map2[] = "010010";
    char map3[] = "011110";
    char map4[] = "000000";
//  char map0[] = "11111111";
//	char map1[] = "10001001";
//	char map2[] = "10010001";
//	char map3[] = "10110001";
//	char map4[] = "11100001";

    char *map[] = { map0, map1, map2, map3, map4 };

    t_point size = (t_point){6, 5};  // width = 6, height = 5
//    t_point size = (t_point){8, 5};  // width = 6, height = 5 x and y
    t_point begin = (t_point){2, 2}; // starting point vertical horizontal

    write(1, "Before:\n", 8);
    ft_print_map(map, size);

    ft_flood_fill(map, size, begin);

    write(1, "\nAfter:\n", 8);
    ft_print_map(map, size);

    return 0;
}
