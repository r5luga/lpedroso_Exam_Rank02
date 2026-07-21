#include <unistd.h>
#include <stdlib.h>

void ft_writenl()
{
    write(1, "\n", 1);
}

int ft_islcc(char *s)
{
    int i = 0;
    
    if (s[i] >= 'A' && s[i] <= 'Z')
        return 0;
    while (s[i])
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            i++;
        else if (s[i] >= 'A' && s[i] <= 'Z')
            i++;
        else
            return 0;
    }
    return 1;
}

int ft_countsc(char *s)
{
    int i = 0;
    int count = 0;
    
    while (s[i])
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            count = count + 2;
        else
            count++;
        i++;
    }
    count ++;
    return count;
}

void ft_lcctosc(char *lcc, char *sc)
{
    int i = 0;
    int j = 0;
    
    while (lcc[i])
    {
        if (lcc[i] >= 'A' && lcc[i] <= 'Z')
        {
            sc[j] = '_';
            j++;
            sc[j] = lcc[i] + 32;
        }
        else
            sc[j] = lcc[i];
        i++;
        j++;
    }
    sc[j] = '\n';
}

int main(int argc, char **argv)
{
    char *sc;
    
    if (argc != 2)
        return (ft_writenl(), 0);
    if (!ft_islcc(argv[1]))
        return (ft_writenl(), 0);
    sc = malloc(ft_countsc(argv[1]));
    if (!sc)
        return (ft_writenl(), 0);
    ft_lcctosc(argv[1], sc);
    write(1, sc, ft_countsc(argv[1]));
    return (ft_writenl(), 0);
}
