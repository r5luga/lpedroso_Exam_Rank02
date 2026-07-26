#include "ft_list_size.h"

int	ft_list_size(t_list *begin_list)
{
    int count = 0;
    
    t_list *tl = begin_list;
    while(tl)
    {
        tl = tl->next;
        count++;
    }
    return count;
}
