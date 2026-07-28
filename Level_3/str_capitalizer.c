#include <unistd.h>

static int ft_strlen(char *s)
{
    int count = 0;
    while (s[count])
        count ++;
    return count;
}

static void ft_putstr(char *s)
{
    write(1, s, ft_strlen(s));
}

static void ft_putchar(char c)
{
    write(1, &c, 1);
}

static int ft_isstart(char c)
{
    return (c == ' ' || c == '\t');
}

static int ft_isupper(char c)
{
    return (c >= 'A' && c <= 'Z');
}

static int ft_islower(char c)
{
    return (c >= 'a' && c <= 'z');
}

static char ft_toupper(char c)
{
    if(ft_islower(c))
        return (c - 32);
    return c;
}

static char ft_tolower(char c)
{
    if(ft_isupper(c))
        return (c + 32);
    return c;
}

static void ft_capword(char *s)
{
    int i = 0;
    int is_word = 1;
    
    while(s[i])
    {
        if (ft_isstart(s[i]))
        {
            is_word = 1;
            ft_putchar(s[i]);
        }
        else
        {
            if (is_word && ft_islower(s[i]))
                ft_putchar(ft_toupper(s[i]));
            else if (!is_word & (ft_isupper(s[i])))
                ft_putchar(ft_tolower(s[i]));
            else
                ft_putchar(s[i]);
            is_word = 0;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    int i = 1;
    
    if (argc < 2)
        return (ft_putstr("\n"), 0);
    
    while ( i < argc)
    {
        ft_putstr(argv[i]);
        ft_putstr("\n");
        ft_capword(argv[i]);
        ft_putchar('\n');
        i++;
    }
    return 0;
}
