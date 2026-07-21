#include <unistd.h>

void ft_writenl()
{
    write(1, "\n", 1);
}

void ft_writemirror(char *s)
{
    int i = 0;
    char c;
    
    while(s[i])
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            c = 'z' - (s[i] - 'a'); 
        else if (s[i] >= 'A' && s[i] <= 'Z')
            c = 'Z' - (s[i] - 'A');
        else
            c = s[i];
        write(1, &c, 1);
        i++;
    }
    
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (ft_writenl(), 0);
    ft_writemirror(argv[1]);
    return (ft_writenl(), 0);
}
