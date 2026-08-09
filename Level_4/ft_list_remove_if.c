#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

static t_list *ft_newnode(void *data)
{
    t_list *t = malloc(sizeof(t_list));
    if (!t)
        return NULL;
        
    t->data = data;
    t->next = NULL;
    return t;
}

static t_list *ft_appendnode(t_list **lst, void *data)
{
    t_list *t = ft_newnode(data);
    if (!t)
        return NULL;
        
    t_list *tmp;
    
    if (!*lst)
        return(*lst = t);
        
    tmp = *lst;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = t;
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

int ft_cmp_int(void *a, void *b)
{
    return (*(int *)a - *(int *)b);
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *curr;
    t_list *temp;

    while (*begin_list && (*cmp)((*begin_list)->data, data_ref) == 0)
    {
        temp = *begin_list;
        *begin_list = (*begin_list)->next;
        free(temp->data);
        free(temp);
    }
    curr = *begin_list;
    while (curr && curr->next)
    {
        if ((*cmp)(curr->next->data, data_ref) == 0)
        {
            temp = curr->next;
            curr->next = temp->next;
            free(temp->data);
            free(temp);
        }
        else
            curr = curr->next;
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
    
    t_list *curr = my_list; // so my_list points to header
    while (curr)
    {
        void *ref = curr->data;
        t_list *ml_next = curr->next;
        
        ft_list_remove_if(&ml_next, ref, ft_cmp_int);
        
        curr->next = ml_next;
        curr = curr->next;
    }
    ft_printlist(my_list, ft_printint);
    
    ft_freelist(my_list);
    return 0;
}
