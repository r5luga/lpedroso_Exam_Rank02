#include <stdlib.h>
#include <unistd.h>
#include "sort_list.h"

#include <stdio.h> // for printf_list

static void ft_printflist(t_list *lst)
{
    while (lst)
    {
        printf("%d ", lst->data);
        lst = lst->next;
    }
    printf("\n");
}

static void    ft_printlist(t_list *lst)
{
    while (lst)
    {
        char buf[12];
        int len = 0;
        int n = lst->data;

        if (n == 0)
            buf[len++] = '0';
        else
        {
            if (n < 0)
            {
                buf[len++] = '-';
                n = -n;
            }
            int tmp = n;
            int digits = 0;
            while (tmp)
            {
                tmp /= 10;
                digits++;
            }
            for (int i = digits - 1; i >= 0; i--)
            {
                buf[len + i] = (n % 10) + '0';
                n /= 10;
            }
            len += digits;
        }
        write(1, buf, len);
        write(1, " ", 1);
        lst = lst->next;
    }
    write(1, "\n", 1);
}

static t_list  *ft_newnode(int value)
{
    t_list *n = malloc(sizeof(t_list));
    n->data = value;
    n->next = NULL;
    return n;
}

static void    ft_append(t_list **lst, int value)
{
    t_list *n = ft_newnode(value);
    if (!*lst)
    {
        *lst = n;
        return;
    }
    t_list *tmp = *lst;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = n;
}

int ft_ascending(int a, int b)
{
	return (a <= b);
}

int main(void)
{
    t_list *lst = NULL;

    ft_append(&lst, 42);
    ft_append(&lst, 3);
    ft_append(&lst, 15);
    ft_append(&lst, -7);
    ft_append(&lst, 99);
    ft_append(&lst, 0);

    write(1, "Before: ", 8);
    ft_printlist(lst);

    lst = sort_list(lst, ft_ascending);

    write(1, "After:  ", 8);
    ft_printflist(lst);

    return 0;
}
