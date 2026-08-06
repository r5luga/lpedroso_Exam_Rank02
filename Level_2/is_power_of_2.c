#include <stdio.h>
#include <stdlib.h>

int	    is_power_of_2(unsigned int n)
{
    if (n == 0 )
        return 0;
    if (n == 1)
        return 1;
    while (n % 2 == 0)
        n /= 2;
    return (n == 1);
}

int	    is_power_of_2_bit(unsigned int n)
{
    return (n != 0 && (n & (n - 1)) == 0);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 0;
    unsigned int i = atoi(argv[1]);
    
    printf("1 % 2 %d\n",1 % 2); // is 1
    
    printf("is %u a power of 2? %d\n", i, is_power_of_2(i));
    printf("is %u a power of 2? %d\n", i, is_power_of_2_bit(i));
    return 0;
}
