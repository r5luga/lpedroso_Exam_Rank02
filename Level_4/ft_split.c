#include <stdlib.h>

static int ft_isseparator(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}
static int ft_countwords(char *s)
{
    int i = 0;
    int count = 0;
    
    while (s[i])
    {
        while (s[i] && ft_isseparator(s[i]))
            i++;
        if (s[i] && !ft_isseparator(s[i]))
            count ++;
            while (s[i] && !ft_isseparator(s[i]))
                i++;
    }
    return count;
}
static char *ft_malloc_word(char *s)
{
    int len = 0;
    int i = 0;
    
    while (s[len] && !ft_isseparator(s[len]))
        len++;
    char *word = malloc((sizeof(char) * len) + 1);
    if (!word)
        return NULL;
    while (i < len)
    {
        word[i] = s[i];
        i++;
    }
    word[i] = '\0';
    return word;
}
static void ft_freeall(char **tab, int i)
{
    while (i >= 0)
        free(tab[i--]);
    free(tab);
}
char    **ft_split(char *str)
{
    int i = 0;
    int w = 0;
    char **tab = malloc((ft_countwords(str) + 1) * sizeof(char *));
    if (!tab)
        return NULL;
    while (str[i])
    {
        while (str[i] && ft_isseparator(str[i]))
            i++;
            
        if (str[i] && !ft_isseparator(str[i]))
        {
            tab[w] = ft_malloc_word(&str[i]);
            if (!tab[w])
            {
                ft_freeall(tab, w - 1);
                return NULL;
            }
            w++;
            while (str[i] && !ft_isseparator(str[i]))
                i++;
        }
    }
    tab[w] = NULL;
    return tab;
}

#include <stdio.h>

int main(int argc, char **argv)
{
    int i = 0;
    
    if (argc != 2)
        return 0;

    printf("%s\n", argv[1]);
    
    char **strs = ft_split(argv[1]);
    
    while (strs[i] != NULL)
    {
        printf("%s\n", strs[i]);
        i++;
    }
    
    return 0;
}
