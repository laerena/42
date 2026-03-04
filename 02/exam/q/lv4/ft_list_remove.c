#include "ft_list.h"
#include <stdlib.h>
/*
void ft_list_remove_if(t_list **begin_list, void *data_ref, int(*cmp)())
{
    t_list *tmp;
    
    if ((*begin_list == NULL) || (begin_list == NULL))
        return ;
    if (cmp((*begin_list)->data, data_ref) == 0x0)
    {
        tmp = *begin_list;
        *begin_list = ((*begin_list)->next);
        free(tmp);
        ft_list_remove_if(begin_list, data_ref, cmp);
    }
    else
        ft_list_remove_if(&((*begin_list)->next), data_ref, cmp);
}*/

void ft_list_remove_if(t_list **begin_list, void*data_ref, int (*cmp)())
{
    t_list *current;
    t_list *previous;
    t_list *next;

    previous = 0;
    current = *begin_list;
    while (current)
    {
        next = current->next;
        if ((cmp(current->data, data_ref) == 0))
        {
            if (previous == 0)
                *begin_list = current->next;
            else
                previous->next = current->next;//skip over current
            free(current);
        }
        else
            previous = current;
        current = next;
    }
}