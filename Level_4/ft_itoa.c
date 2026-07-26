#include <stdlib.h>

static int ft_intlen(long n)
{
    int count = 0;
    
    if (n <= 0)
        count++; // negative or zero
    while(n != 0)
    {
        n /= 10;
        count++;
    }
    return count;
}

char	*ft_itoa(int nbr)
{
    char numbers[] = "0123456789";
    long ln = nbr;       // use long to safely handle INT_MIN
    int len = ft_intlen(ln);
    char *numc = malloc(sizeof(char) * (len + 1));
    if (!numc)
        return NULL;
    numc[len] = '\0';
    if (ln == 0)
        return (numc[0] = '0', numc);
    if (ln < 0)
    {
        numc[0] = '-';
        ln *= -1;
    }
    while (ln != 0)
    {
        numc[--len] = numbers[ln % 10];
        ln /= 10;
    }
    return numc;
}

#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 2)
        return 0;
    
    int n = atoi(argv[1]);
    printf("Number as string: %s", ft_itoa(n));   
}
