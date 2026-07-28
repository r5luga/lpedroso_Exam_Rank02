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
static int ft_islower(char c)
{
    return(c >= 'a' && c <= 'z');
}
static int ft_isupper(char c)
{
    return(c >= 'A' && c <= 'Z');
}
static int ft_isletter(char c)
{
    return (ft_islower(c) || ft_isupper(c));
}
static char ft_toupper(char c)
{
    if (ft_islower(c))
        return (c - 32);
    return c;
}
static char ft_tolower(char c)
{
    if (ft_isupper(c))
        return (c + 32);
    return c;
}
static void ft_caplword(char *s)
{
    int i = 0;
    int is_last_letter = 0;
    
    while (s[i])
    {
        if (ft_isletter(s[i]) && !ft_isletter(s[i + 1]))
            is_last_letter = 1;
        else
            is_last_letter = 0;
        if (is_last_letter)
            ft_putchar(ft_toupper(s[i]));
        else
            ft_putchar(ft_tolower(s[i]));
        i++;
    }
}
int main(int argc, char **argv)
{
    int i = 1;
    
    if (argc < 2)
        return(ft_putstr("\n"), 0);
        
    while (i < argc)
    {
        ft_putstr(argv[i]);
        ft_putstr("\n");
        ft_caplword(argv[i]);
        ft_putchar('\n');
        i++;
    }
    return 0;
}
