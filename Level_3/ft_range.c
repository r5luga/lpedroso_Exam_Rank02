#include <stdio.h>
#include <stdlib.h>

static int ft_entries(int start, int end)
{
    int entries = 0;
    
    if (start < end)
    {   
        while (start <= end)
        {
            entries++;
            start++;
        }
    }
    else if (start > end)
    {
        while (end <= start)
        {
            entries++;
            end++;
        }
    }
    else
        entries = 1;
    return entries;
}

int     *ft_range(int start, int end)
{   
    int i = 0;

    int entries = ft_entries(start, end);
    
    int *tabi = malloc(sizeof(int) * entries);
    if (!tabi)
        return NULL;
    
    if (start < end)
        while (start + i <= end)
        {
            tabi[i] = start + i;
            i++;
        }
    else if (start > end)
        while (end + i <= start)
        {
            tabi[i] = start - i;
            i++;
        }
    else
        tabi[i] = start;
    return tabi;
}

int main(int argc, char **argv)
{
    int i = 0;
    
    if (argc != 3)
        return 0;
        
    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    
    int entries = ft_entries(start, end);
    int *tabi = ft_range(start, end);
    
    while (i < entries)
    {
        printf("entry %d is equal to %d\n", i, tabi[i]);
        i++;
    }
    
    free(tabi);
    
    return 0;
}
