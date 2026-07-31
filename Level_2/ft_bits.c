#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	print_bits(unsigned char octet)
{
    int i = 7;
    char bit;
    
    while (i >= 0)
    {
        if (octet & (1 << i))
            bit = '1';
        else
            bit = '0';
        write(1, &bit, 1);
        i--;
    }
}

unsigned char	reverse_bits(unsigned char octet)
{
    int i = 0;
    unsigned char bit = 0;
    
    while (i < 8)
    {
        if (octet & (1 << i))
            bit = bit | (1 << (7 - i));
        i++;
    }
    return bit;
}

unsigned char	swap_bits(unsigned char octet)
{
    return ((octet << 4) | (octet >> 4));    
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 0;
    print_bits(atoi(argv[1]));
    printf("\n");
    print_bits(reverse_bits(atoi(argv[1])));
    printf("\n");
    print_bits(swap_bits(atoi(argv[1])));
    return 0;
}
