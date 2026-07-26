#include <stdlib.h>
#include <stdio.h>
#include "ft_list_size.h"

static t_list *ft_newnode(int *i)
{
    t_list *n = malloc(sizeof(t_list));
    n->data = i;
    n->next = NULL;
    return n;
}

static void ft_appendnode(t_list **lst, int *i)
{
    t_list *n = ft_newnode(i);
    if (!*lst)
        *lst = n;
    else
    {
        t_list *t = *lst;
        while (t->next)
            t = t->next;
        t->next = n;
    }
}

static void ft_printf_list_i(t_list *lst)
{
    while (lst)
    {
        printf("%d ", *(int *)lst->data);
        lst = lst->next;
    }
    printf("\n");
}

void static ft_list_free(t_list *lst)
{
    t_list *tmp;

    while (lst)
    {
        tmp = lst->next;              // save next node
        free(lst->data);              // free the int* (or whatever data is)
        free(lst);                    // free the node itself
        lst = tmp;                    // move forward
    }
}

int main( int argc, char **argv)
{
    t_list *lst = NULL;
    int i;
    
    if (argc == 0)
        return 0;
    for (i = 1; i < argc; i++)
    {
        int *pi = malloc(sizeof(int));
        *pi = atoi(argv[i]);
        ft_appendnode(&lst, pi);
    }
    printf("list size: %d", ft_list_size(lst));   
    printf("\n");
    ft_printf_list_i(lst);   
    ft_list_free(lst);
    return 0;
}
