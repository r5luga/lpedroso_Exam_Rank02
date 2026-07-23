#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
    int i = 0, j;
    if (s1 == NULL || s2 == NULL)
        return NULL;
    while (s1[i])
    {
        j = 0;
        while(s2[j])
        {
            if (s1[i] == s2[j])
                return (char *)&s1[i];
            j++;
        }
        i++;
    }
    return NULL;
}

int main(int argc, char **argv)
{
    if (argc != 3)
        return (0);
    printf("ft_strpbrk: %s\n", ft_strpbrk(argv[1], argv[2]));
    printf("   strpbrk: %s\n", strpbrk(argv[1], argv[2]));
}
