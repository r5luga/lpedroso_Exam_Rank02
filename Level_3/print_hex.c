#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_atoi(char *s)
{
    int i = 0;
    int sign = 1;
    int num = 0;
    while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
        i++;
    while (s[i] == '-' || s[i] == '+')
    {
        if (s[i] == '-')
            sign *= -1;
        i++;
    }
    while (s[i] >= '0' && s[i] <= '9')
    {
        num = num * 10 + (s[i] - '0');
        i++;
    }
    return num * sign;
}

void ft_itoh(int num)
{
    char h[16] = "0123456789abcdef";
    
    if (num >= 16)
        ft_itoh(num / 16);
    write(1, &h[num % 16], 1);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return(ft_putchar('\n'), 0);
    ft_itoh(ft_atoi(argv[1]));
    return(ft_putchar('\n'), 0);
}
