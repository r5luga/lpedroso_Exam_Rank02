#include <stddef.h>
#include <stdio.h>

size_t	ft_strspn(const char *s, const char *accept)
{
    size_t i = 0;
    size_t j = 0;
    
    i = 0;
    while (s[i])
    {
        j = 0;
        while (accept[j])
        {
            if (s[i] == accept[j])
                break;
            j++;
        }
        if (!accept[j])
            return i;
        i++;
    }
    return i;
}

int main(int argc, char **argv)
{
    if (argc != 3)
        return 0;
    
    printf("count s2 in s1 %zu\n", ft_strspn(argv[1], argv[2]));
    
    return 0;
}
