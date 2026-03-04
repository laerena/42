#include "ft_list.h"

int ft_list_size(t_list *begin_list)
{
    int i = 0;
    //while the next element is not null
    while (begin_list->next)
    {
        //set the original pointer point to the next element
        // and increment the counter
        begin_list = begin_list->next;
        i++;
    }
    return (i);
}