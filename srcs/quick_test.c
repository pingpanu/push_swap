#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "operation.h"
#include "push_swap.h"

static void print_lst(t_stack *lst)
{
    if (lst == NULL)
        printf("Linked list is empty");
    while(lst != NULL)
    {
        printf("%d ->", lst->data);
        lst = lst->next;
    }
    printf("\n");
}

static int  ft_abs(int nbr)
{
    if (nbr < 0)
        return (nbr * -1);
    return (nbr);
}

static int  get_mid(t_stack *lst, t_param par)
{
    int     mid;
    int     cur;

    mid = (par.max[0] + par.min[0]) / 2;
    cur = lst->data;
    while (lst != NULL)
    {
        if (ft_abs(mid - lst->data) < (mid - cur))
            cur = lst->data;
        lst = lst->next; 
    }
    return (cur);
}

static int  get_min(t_stack *lst)
{
    int min;

    min = INT_MAX;
    while (lst != NULL)
    {
        if (min > lst->data)
            min = lst->data;
        lst = lst->next;
    }
    return (min);
}

int main()
{ 
    t_param a_par;
    int     a_mid;
    int     arr[10];
    t_stack *a;
    t_stack *b;
    t_stack *new;


    a = NULL;
    b = NULL;
    for (int i = 0; i < 10; i++)
    {
        new = ft_lstnew(rand() % 100);
        ft_lstadd_back(&a, new);
    }
    print_lst(a);
    a_par = get_stack_param(&a);
    a_mid = get_mid(a, a_par);
    printf("%d\n",a_mid);
    while (a_par.min[0] < a_mid)
    {
        if(a->data < a_mid)
        {
            push_b(&a, &b);
            a_par.min[0] = get_min(a);
        }
        rotate_a(&a);
    }
    print_lst(a);
    print_lst(b);
    return (0);
}