#include <stdlib.h>
#include <unistd.h>
#include "list.h"

#include <stdio.h> // for printf_list

static void printf_list(t_list *lst)
{
    while (lst)
    {
        printf("%d ", lst->data);
        lst = lst->next;
    }
    printf("\n");
}

static void    print_list(t_list *lst)
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

static t_list  *new_node(int value)
{
    t_list *n = malloc(sizeof(t_list));
    n->data = value;
    n->next = NULL;
    return n;
}

static void    append(t_list **lst, int value)
{
    t_list *n = new_node(value);
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

int ascending(int a, int b)
{
	return (a <= b);
}

int main(void)
{
    t_list *lst = NULL;

    append(&lst, 42);
    append(&lst, 3);
    append(&lst, 15);
    append(&lst, -7);
    append(&lst, 99);
    append(&lst, 0);

    write(1, "Before: ", 8);
    print_list(lst);

    lst = sort_list(lst, ascending);

    write(1, "After:  ", 8);
    print_list(lst);

    return 0;
}
