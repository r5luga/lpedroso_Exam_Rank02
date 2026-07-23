#include <unistd.h>

static void ft_putchar(char c)
{
    write(1, &c, 1);
}
static void ft_putzero()
{
    ft_putchar('0'); 
    ft_putchar('\n');
}
static int ft_atoi(char *s)
{
    int i = 0, num = 0;
    int sign = 1;
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
    return (num * sign);
}
static int ft_isprime(int num)
{
    int i = 2;

    if (num < 2)
        return 0;
    while (i * i <= num)
    {
        if (num % i == 0)
            return 0;
        i++;
    }
    return 1;
}
static void ft_itoa(int n)
{
    char num[10] = "0123456789";
    
    if (n >= 10)
        ft_itoa(n / 10);
    write(1, &num[n % 10], 1);
}
int main(int argc, char **argv)
{
    int num, sum = 0;
    if (argc != 2)
        return (ft_putzero(), 0);
    num = ft_atoi(argv[1]);
    if ( num <= 0)
        return (ft_putzero(), 0);
    int i = 2;
    while ( i <= num )
    {
        if (ft_isprime(i))
            sum += i;
        i++;
    }
    ft_itoa(sum);
    ft_putchar('\n');
    return 0;
}
