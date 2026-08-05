#include <stdio.h>
#include <stdlib.h>

static int ft_strlen(char *str)
{
    int i = 0;
    
    while (str[i])
    {
        i++;
    }
    return i;
}

char    *ft_strrev(char *str)
{
    int i = 0;
    int len = ft_strlen(str);
    
    char *tmp = malloc((sizeof(char) * len) + 1);
    if (!tmp)
        return NULL;
    while (str[i])
    {
        tmp[len-1-i] = str[i];
        i++;
    }
    tmp[i] = '\0';
    return tmp;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 0;
    
    char *str = ft_strrev(argv[1]);
    
    printf("argv before %s \n argv after %s \n", argv[1], str);
    
    return 0;
}
