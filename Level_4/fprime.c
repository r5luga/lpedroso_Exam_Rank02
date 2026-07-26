#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 2)
        return (printf("\n"), 0);

    int n = atoi(argv[1]);
    int i = 2;
    
    if (n == 1)
        return (printf("1\n"), 0);
        
    while ( i <= n)
    {
        if ( n % i == 0)
        {
            printf("%d", i);
            n /= i;
            if (n > 1)
                printf("*");
        }
        else
            i++;
    }
    
    return (printf("\n"), 0);
}
