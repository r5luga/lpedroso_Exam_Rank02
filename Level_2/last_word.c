#include <unistd.h>

void ft_putstr(char *s)
{
    int i = 0;
    
    while (s[i])
    {
        if (s[i] != ' ' && s[i] != '\t')
            write(1, &s[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    int i = 0;
    
    if (argc != 2)
        return (write(1, "\n", 1), 0);

    while (argv[1][i])
        i++;
    if (i == 0)
        return (write(1, "\n", 1), 0);
    i--;
    
    while (i >= 0 && (argv[1][i] == ' ' || argv[1][i] == '\t'))
        i--;
    if (i < 0)
        return (write(1, "\n", 1), 0);
 
    while (i >= 0 && argv[1][i] != ' ' && argv[1][i] != '\t')
        i--;
        
    ft_putstr(&argv[1][i+1]);
    return (write(1, "\n", 1), 0);
}
