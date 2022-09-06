/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:52:03 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/06 16:23:33 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

static int pivot_push_b(t_stack **a, t_stack **b)
{
    t_param a_par;
    float   a_pivot;
    float   a_mid;
    int         chunk_b_size;

    chunk_b_size = 0;
    /*a_pivot is the mid of the range of stack a*/
    a_pivot = ((float)a_par.max[0] - (float)a_par.min[0]) / 2;
    /*a_mid is the mid_size of the stack_a*/
    a_mid = (float)a_par.stack_size / 2;
    while (a_par.stack_size > a_mid)
    {
        if ((*a)->data < a_pivot)
        {
            push_b(a, b);
            chunk_b_size++;
            a_par.stack_size--;
        }
        else
            rotate_a(a);
    }
    return (chunk_b_size);
}

void    quick_sort(t_stack **a, t_stack **b, int chunk_a)
{
    int     chunk_b[500];
    int     i;

    i = -1;
    while (chunk_a > 3)
    {
        if (stack_sorted(**a, chuck_a))
            break ;
        chunk_b[++i] = pivot_push_b(a, b);
        chunk_a -= chuck_b[i];
    }
    tri_sort(a, get_stack_param(a));
    while (i >= 0)
    {
        if (chunk_b[i] > 3)
        {
            chunk_a = pivot_push_a(a, b, chunk_b[i]);
            quick_sort(a, b, chunk_a);
            chunk_b[i] -= chunk_a;
        }
        else
            sort_push_back(a, b, chunk_b[i--]);
    }
}