#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

static t_list *ft_newnode(void *data)
{
    t_list *n = malloc(sizeof(t_list));
    if (!n)
        return NULL;

    n->data = data;
    n->next = NULL;
    return n;
}

static void ft_appendnode(t_list **lst, void *data)
{
    t_list *n = ft_newnode(data);
    if (!n)
        return;
    t_list *cur;

    if (!*lst)
    {
        *lst = n;
        return;
    }
    cur = *lst;
    while (cur->next)
        cur = cur->next;
    cur->next = n;
}

void ft_printstr(void *p)
{
    printf("%s ", (char *)p);
}

void ft_printint(void *p)
{
    printf("%d ", *(int *)p);
}

static void ft_printlist(t_list *l, void (*ft_printdata)(void *))
{
    int i = 0;
    t_list *tmp;
    
    tmp = l;
    while (tmp)
    {
        printf("List entry %d: ", i);
        ft_printdata(tmp->data);
        tmp = tmp->next;
        printf("\n");
        i++;
    }
}

static void ft_freelist(t_list *lst)
{
    t_list *tmp;

    while (lst)
    {
        tmp = lst->next;
        free(lst->data);
        free(lst);
        lst = tmp;
    }
}

void ft_dupint(void *data)
{
    int *p = (int *)data;
    
    *p = *p * 2;
}

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    t_list *tmp;
    
    if (!begin_list || !f)
        return;
    tmp = begin_list;
    while (tmp)
    {
        (*f)(tmp->data);
        tmp = tmp->next;
    }
}

int main(int argc, char **argv)
{
    t_list *my_list = NULL;
    int i = 0;
    
    if (argc < 2)
        return (0);
    
    int l_entries = argc - 1;
    
    while (i < l_entries) // i starts at zero
    {
        int *pi = malloc(sizeof(int));
        *pi = atoi(argv[i+1]); // argv zero is program name
        ft_appendnode(&my_list, pi );
        i++;
    }
    ft_printlist(my_list, ft_printint);
    
    ft_list_foreach(my_list, ft_dupint);
    ft_list_foreach(my_list, ft_printint);
    printf("\n");
    ft_freelist(my_list);
    return 0;
}
