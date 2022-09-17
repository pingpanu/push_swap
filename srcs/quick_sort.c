/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:52:03 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/17 23:09:49 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"
#include <stdio.h>

static int  pivot_push_a(t_stack **a, t_stack **b, int chunk_b_size)
{
    t_param b_par;
    int     b_pivot;
    int     chunk_a_size;

    chunk_a_size = 0;
    b_par = get_stack_param(b, chunk_b_size);
    b_pivot = get_mid(*b, b_par);
    while (b_par.max[0] > b_pivot)
    {
        while((*b)->data < b_pivot)
            rotate_b(b);
        push_a(a, b);
        chunk_a_size++;
        chunk_b_size--;
        b_par = get_stack_param(b, chunk_b_size);
    }
    return (chunk_a_size);
}

static int  pivot_push_b(t_stack **a, t_stack **b, int chunk_a_size)
{
    t_param a_par;
    int     a_pivot;
    int     chunk_b_size;

    chunk_b_size = 0;
    a_par = get_stack_param(a, chunk_a_size);
    a_pivot = get_mid(*a, a_par);
    while (a_par.min[0] <= a_pivot)
    {
        while ((*a)->data > a_pivot)
            rotate_a(a);
        push_b(a, b);
        chunk_b_size++;
        chunk_a_size--;
        a_par = get_stack_param(a, chunk_a_size);
    }
    return (chunk_b_size);
}

void    quick_sort(t_stack **a, t_stack **b, int chunk_a)
{
    int     i;
    int     chunk_b[500];
    int     limits;

    if (check_ascend(a) && ft_lstsize(*b) == 0)
        exit(0);
    i = -1;
    limits = 20 + (8 * ft_log(chunk_a - 100));
    /*15 optimized for 100
    40 optimized for 500*/
    while (chunk_a > limits)
    {
        if (check_ascend(a))
            break ;
        chunk_b[++i] = pivot_push_b(a, b, chunk_a);
        chunk_a -= chunk_b[i];
    }
    if (!check_ascend(a))
        insertion_sort(a, b, ft_lstsize(*b));
    while (i >= 0)
    {
        /*20 optimized for 100
        50 optimized for 500 */
        if (chunk_b[i] > (limits / 0.75))
        {
            chunk_a = pivot_push_a(a, b, chunk_b[i]);
            quick_sort(a, b, chunk_a);
            chunk_b[i] -= chunk_a;
        }
        else
        {
            while (chunk_b[i] > 0)
            {
                push_back(a, b);
                chunk_b[i]--;
            }
            if (!check_ascend(a))
                insertion_sort(a, b, ft_lstsize(*b));
            i--;
        }
    }
}