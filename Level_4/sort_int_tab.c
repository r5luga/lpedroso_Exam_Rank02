#include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	int				tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int main( )
{
    int tabi[] = {51,42,33,24,15};
    unsigned int tabsize = 5;
    int i = 0;
    
    while (i < tabsize)
    {
        printf("Entry %d: %d\n", i, tabi[i]);    
        i++;
    }
    sort_int_tab(tabi, tabsize);
    printf("After sorting\n");
    
    i = 0;
    while (i < tabsize)
    {
        printf("Entry %d: %d\n", i, tabi[i]);    
        i++;
    }
    return 0;
}
