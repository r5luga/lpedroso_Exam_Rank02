#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "do_op.h"

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    int n1, n2, res;
    
    if (argc != 4)
        return(ft_putchar('\n'), 0);
    n1 = atoi(argv[1]);
    n2 = atoi(argv[3]);
    if (argv[2][0] == '+')
        res = n1 + n2;
    else if (argv[2][0] == '-')
        res = n1 - n2;
    else if (argv[2][0] == '*')
        res = n1 * n2;
    else if (argv[2][0] == '/')
        res = n1 / n2;
    else if (argv[2][0] == '%')
        res = n1 % n2;
    else
        res = 0;
    printf("%d\n", res);
    return(0);
}
