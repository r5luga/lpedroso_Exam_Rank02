#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int    ft_strcmp(char *s1, char *s2)
{
    int cs1 = 0, cs2 = 0, i = 0;
    
    while (s1[cs1])
        cs1++;
    while (s2[cs2])
        cs2++;
    while (s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return( s1[i] - s2[i] );
        i++;
    }
    return( cs1 - cs2 );
}

int    ft_strcmp2(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    // Compares bytes as unsigned char (important!)
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int main(int argc, char **argv)
{
    if (argc != 3)
        return (write(1, "\n", 1), 0);
    printf("ft_strcmp: %d\n", ft_strcmp2(argv[1], argv[2]));
    printf("   strcmp: %d\n", strcmp(argv[1], argv[2]));
}
