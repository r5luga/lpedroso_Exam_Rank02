#include <stdlib.h>
#include <stdio.h>

// The GCD (Greatest Common Divisor) is the 
// largest positive integer that divides two numbers without 
// leaving a remainder
unsigned int gcd(unsigned int a, unsigned int b)
{
    while (b != 0)
    {
        unsigned int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

unsigned int lcm(unsigned int a, unsigned int b)
{
    if (a == 0 || b == 0)
        return 0;
    return (a / gcd(a, b)) * b;
}

// lcm brute force
unsigned int    lcm_bf(unsigned int a, unsigned int b)
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
    printf("LCM BF  of a=%u and b=%u is %u\n", a, b, lcm_bf(a, b));
    printf("LCM GCD of a=%u and b=%u is %u\n", a, b, lcm_bf(a, b));
    
    return 0;
}
