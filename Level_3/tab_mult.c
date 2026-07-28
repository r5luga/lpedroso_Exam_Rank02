#include <unistd.h>

static void ft_putchar(char c)
{
    write(1, &c, 1);
}

static void ft_writeint(int num)
{
    char numlist[] = "0123456789";
    
    if (num < 0) // no need as cheack in man for positive number
    {
        ft_putchar('-');
        num = -num;
    }
    if (num >= 10)
        ft_writeint(num / 10);
    ft_putchar(numlist[num % 10]);
}

static int ft_atoi(char *s)
{
    int i = 0; int num = 0; int sign = 1;
    
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

int main(int argc, char **argv)
{
    int i = 1;
    
    if (argc != 2)
        return(ft_putchar('\n'), 0);
    
    int tab = ft_atoi(argv[1]);
    
    if (tab < 0)
        return(ft_putchar('\n'), 0);
    
    while (i <= 9)
    {
        int result = tab * i;
        ft_writeint(i);
        write(1, " * ", 3);
        ft_writeint(tab);
        write(1, " = ", 3);
        ft_writeint(result);
        ft_putchar('\n');
        i++;
    }
    return 0;
}
