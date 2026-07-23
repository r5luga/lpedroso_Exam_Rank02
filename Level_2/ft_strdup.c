#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *ft_strdup(const char *s)
{
    size_t i = 0;
    if (s == NULL)
        return NULL;
    char *str = malloc(strlen(s) + 1);
    if (!str)
        return NULL;
    while (s[i])
    {
        str[i] = s[i];
        i++;
    }
    str[i] = '\0';
    return str;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (0);
    printf("ft_strdup: %s\n", ft_strdup(argv[1]));
    printf("   strdup: %s\n", strdup(argv[1]));
}
