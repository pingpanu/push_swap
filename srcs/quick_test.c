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

int main()
{ 
    t_param a_par;
    int     a_mid;
    int     arr[10];
    t_stack *a;
    t_stack *b;
    t_stack *new;
    int     data;

    a = NULL;
    b = NULL;
    for (int i = 0; i < 10; i++)
    {
        new = ft_lstnew(rand() % 100);
        ft_lstadd_back(&a, new);
    }
    print_lst(a);
    a_par = get_stack_param(&a);
    a_mid = (a_par.max[0] + a_par.min[0]) / 2;
    printf("%d\n",a_mid);
    while (a_par.stack_size > 3)
    {
        if (a->data > a_mid)
            rotate_a(&a);
        push_b(&a, &b);
        a_par.stack_size--;
    }
    print_lst(a);
    print_lst(b);
    return (0);
}