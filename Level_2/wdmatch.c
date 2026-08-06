#include <unistd.h>

void ft_putstr(char *s)
{
    int i = 0;
    
    while (s[i])
    {
        write(1, &s[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    int j = 0;
    int i = 0;
    int is_true = 1;

    if (argc != 3)
        return (write(1, "\n", 1), 0);
    while (argv[1][i] != '\0' && is_true == 1)
    {
        while (argv[2][j] != '\0' && (argv[1][i] != argv[2][j]))
            j++;
        if (argv[2][j] == '\0')
            is_true = 0;
        else
            j++;
        i++;
    }
    if (is_true)
        ft_putstr(argv[1]);
    return (write(1, "\n", 1), 0);
}
