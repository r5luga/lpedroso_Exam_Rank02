#include <unistd.h>

void ft_put_letter(char c)
{
    write(1, &c, 1);
}

void ft_putcapital(char c)
{
    char l;
    if (c >= 'a' && c <= 'z')
        l = c - 32;
    else
        l = c;
    ft_put_letter(l);
}

int main(int argc, char **argv)
{
    int i = 0;
    
    if (argc != 2)
        return(write(1, "\n", 1), 0);
    while (argv[1][i])
    {
        if (argv[1][i] == '_')
        {
            i++;
            ft_putcapital(argv[1][i]);
        }
        else
            ft_put_letter(argv[1][i]);
        i++;
    }
    return(write(1, "\n", 1), 0);
}
