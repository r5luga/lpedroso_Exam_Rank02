#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_atoi(const char *str)
{
    int i = 0;
    int sign = 1;
    int num = 0;

    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        num = num * 10 + (str[i] - '0');
        i++;
    }
    return (num * sign);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return(0);
    printf("ft_atoi: %d\n", ft_atoi(argv[1]));
    printf("   atoi: %d\n", atoi(argv[1]));
    return (0);
}
