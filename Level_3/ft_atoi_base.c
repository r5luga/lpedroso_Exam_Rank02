int ft_base(char c, int str_base)
{
    int i = 0;
    char *lc_hex = "0123456789abcdef";
    char *uc_hex = "0123456789ABCDEF";
    
    while (i < str_base)
    {
        if (c == lc_hex[i] || c == uc_hex[i])
            return i;
        i++;
    }
    return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
    int sum = 0;
    int i = 0;
    int sign = 1;
    
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    
    while (str[i] && ft_base(str[i], str_base) != -1)
    {
        sum = sum * str_base + ft_base(str[i], str_base);
        i++;
    }
    return (sum * sign);
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 3)
        return 0;
        
    int base = atoi(argv[2]);
    int sum = ft_atoi_base(argv[1], base);
    printf("decimal of %s in base %d is %d\n", argv[1], base, sum);
    
    return 0;
}
