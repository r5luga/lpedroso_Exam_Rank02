#include <stdlib.h>
#include <stdio.h>

unsigned int    lcm(unsigned int a, unsigned int b)
{
    unsigned int m;
    
    if (a == 0 || b == 0)
        return (0);
    m = a;
    while (m % b != 0)
        m += a;
    return m;
}

int main(int argc, char **argv)
{
    unsigned int a, b;
    
    if (argc != 3)
        return 0;
    // Least Common Multiple also known as the 
    // lowest common multiple of two (or more) integers
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    printf("Lowest Common Multiple\n");
    printf("LCM of a=%u and b=%u is %u\n", a, b, lcm(a, b));
    
    return 0;
}
