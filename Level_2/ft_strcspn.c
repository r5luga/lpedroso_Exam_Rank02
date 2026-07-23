#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
    size_t i = 0, j = 0;
    while(s[i])
    {
        j = 0;
        while (reject[j])
        {
            if (s[i] == reject[j])
                return(i);
            j++;
        }
        i++;
    }
    return(i);
}

int main(int argc, char **argv)
{
    if (argc != 3)
        return (write(1, "\n", 1), 0);
    printf("ft_strcspn: %zu\n", ft_strcspn(argv[1], argv[2]));
    printf("   strcspn: %zu\n", strcspn(argv[1], argv[2]));
}
