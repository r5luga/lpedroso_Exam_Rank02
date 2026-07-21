#include <unistd.h>
#include <stdlib.h>

void ft_writechar(char c)
{
    write(1, &c, 1);
}

void ft_writesc(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        ft_writechar('_');
        c += 32;
    }
    ft_writechar(c);
}

int main(int argc, char **argv)
{
    int i = 0;
    
    if (argc != 2)
        return(ft_writechar('\n'), 0);
    while (argv[1][i])
    {
        ft_writesc(argv[1][i]);
        i++;
    }
    return(ft_writechar('\n'), 0);
}
