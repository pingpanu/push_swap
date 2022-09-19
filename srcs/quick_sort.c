/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:52:03 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/19 16:55:29 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"
/*#include <stdio.h>

static void     print_lst(t_stack *lst)
{
    if (lst == NULL)
        printf("Linked list is empty\n");
    while (lst != NULL)
    {
        printf("%d ->", lst->data);
        lst = lst->next;
    }
    printf("\n");
}*/

static int  pivot_push_a(t_stack **a, t_stack **b, int chunk_b_size)
{
    t_param b_par;
    int     b_pivot;
    int     chunk_a_size;
    int     rb;

    chunk_a_size = 0;
    rb = 0;
    b_par = get_stack_param(b, chunk_b_size);
    b_pivot = get_mid(*b, b_par);
    while (b_par.max[0] > b_pivot)
    {
        while((*b)->data <= b_pivot)
            rb += rotate_b(b);
        chunk_a_size += push_a(a, b);
        b_par = get_stack_param(b, (chunk_b_size - chunk_a_size));
    }
    if ((ft_lstsize(*b) + chunk_a_size) != chunk_b_size)
    {
        while (rb > 0)
            rb -= r_rotate_b(b);
    }
    return (chunk_a_size);
}

static int  pivot_push_b(t_stack **a, t_stack **b, int chunk_a_size)
{
    t_param a_par;
    int     a_pivot;
    int     chunk_b_size;
    int     ra;

    chunk_b_size = 0;
    ra = 0;
    a_par = get_stack_param(a, chunk_a_size);
    a_pivot = get_mid(*a, a_par);
    while (a_par.min[0] <= a_pivot)
    {
        while ((*a)->data > a_pivot)
            ra += rotate_a(a);
        chunk_b_size += push_b(a, b);
        a_par = get_stack_param(a, (chunk_a_size - chunk_b_size));
    }
    if ((ft_lstsize(*a) + chunk_b_size) != chunk_a_size)
    {
        while (ra > 0)
            ra -= r_rotate_a(a);
    }
    return (chunk_b_size);
}

void    quick_sort(t_stack **a, t_stack **b, int chunk_a)
{
    int     i;
    int     chunk_b[500];

    /*printf("Start of function\n");
    printf("\nstack_a = %d\n", ft_lstsize(*a));
    print_lst(*a);
    printf("\nstack_b = %d\n", ft_lstsize(*b));
    print_lst(*b);*/
    if (check_ascend(a) && ft_lstsize(*b) == 0)
        exit(0);
    i = -1;
    /*depend on performance of insertion sort*/
    while (chunk_a > 3)
    {
        if (check_ascend(a))
            break ;
        chunk_b[++i] = pivot_push_b(a, b, chunk_a);
        chunk_a -= chunk_b[i];
        //printf("chunk_a = %d chunk_b[%d] = %d\n", chunk_a, i, chunk_b[i]);
    }
    if (!check_ascend(a))
    {
        if (ft_lstsize(*a) == 3)
            tri_sort(a, get_stack_param(a, 0));
        else
            insertion_sort(a, b, ft_lstsize(*b));
    }
    /*printf("chunk_a = %d, chunk_b[%d] = %d\n", chunk_a, i, chunk_b[i]);
    printf("\nstack_a = %d\n", ft_lstsize(*a));
    print_lst(*a);
    printf("\nstack_b = %d\n", ft_lstsize(*b));
    print_lst(*b);*/
    while (i >= 0)
    {
        /*20 optimized for 100
        50 optimized for 500*/
        while (chunk_b[i] > 20)
        {
            chunk_a = pivot_push_a(a, b, chunk_b[i]);
            quick_sort(a, b, chunk_a);
            chunk_b[i] -= chunk_a;
        }
        while (chunk_b[i] > 0)
            //chunk_b[i] -= push_a(a, b);
            chunk_b[i] -= push_back(a, b);
        /*printf("Stack a = %d\n", ft_lstsize(*a));
        print_lst(*a);
        printf("Stack b = %d\n", ft_lstsize(*b));
        print_lst(*b);
        if (!check_ascend(a))
            insertion_sort(a, b, ft_lstsize(*b));*/
        i--;
        /*printf("Stack a = %d\n", ft_lstsize(*a));
        print_lst(*a);
        printf("Stack b = %d\n", ft_lstsize(*b));
        print_lst(*b);*/
    }
}