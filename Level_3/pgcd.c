#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("\n");
        return 0;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    //int i = (a < b) ? a : b;
    int i;
    if (a < b)
        i = a;
    else
        i = b;

    while (i > 0)
    {
        if (a % i == 0 && b % i == 0)
        {
            printf("%d\n", i);
            return 0;
        }
        i--;
    }

    return 0;
}
