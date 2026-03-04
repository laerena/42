#include "list.h"
#include <unistd.h>

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
    int tmp;
    t_list *head;

    head = lst; //store pointer to the first element
    if (!lst)
        return (lst);
    while (lst != NULL && lst->next != NULL)
    {
        if ((*cmp)(lst->data, lst->next->data) == 0)
        {
            //simple swap logic
            tmp = lst->data;
            lst->data = lst->next->data;
            lst->next->data = tmp;
            //after a swap restart from the beginning to re-check previous pairs
            lst = head;
        }
        else
            lst = lst->next;
    }
    return (head);
}