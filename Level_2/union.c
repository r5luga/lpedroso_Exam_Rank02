#include <unistd.h>

void ft_print_letter(char l, int *taba)
{
    if (!taba[(unsigned char)l])
    {
        taba[(unsigned char)l] = 1;
        write(1, &l, 1);
    }
}

int main(int argc, char **argv)
{
    int taba[256] = {0};
    int j = 1;
    int i = 0;
    
    if (argc != 3)
        return (write(1, "\n", 1), 0);
    
    j = 1;
    while (j <= 2)
    {
        i = 0;
        while (argv[j][i])
        {
            ft_print_letter(argv[j][i], taba);
            i++;
        }
        j++;
    }
    write(1, "\n", 1);
}
