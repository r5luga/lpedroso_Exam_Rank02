#include <unistd.h>

static void ft_itoa_write(long int l)
{
    if (l >= 10)
        ft_itoa_write(l / 10);
    char c = (l % 10) + '0';
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    long int l;
    
    if (argc == 1)
        return(write(1, "0", 1), 0);
 
    l = argc - 1;
    ft_itoa_write(l);
    return(write(1, "\n", 1), 0);
}
