#include <stdio.h>
#include <stdlib.h>

int		max(int* tab, unsigned int len)
{
    int i = 0;
    int max = 0;
    
    while (i < len)
    {
        if (i == 0)
            max = tab[i];
        if (tab[i] > max)
            max = tab[i];
        i++;
    }
    return max;
}

int main (int argc, char **argv)
{
    int *tab;
    int i = 0;
    
    if (argc <= 1)
        return 0;
    printf("argc %d\n", argc);
    int entries = argc - 1;
    tab = malloc(sizeof(int) * entries);
    if (!tab)
        return 0;
    
    while (i < entries)
    {
        tab[i] = atoi(argv[i+1]);
        printf("tab[%d] = %d\n", i, tab[i]);
        i++;
    }
    printf("max in tab %d\n", max(tab, entries));
    return 0;
}
