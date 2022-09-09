/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:52:03 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/09 15:02:18 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

static int  pivot_push_a(t_stack **a, t_stack **b, int  chunk_size)
{
    t_param b_par;
    int     b_pivot;
    int     chunk_a_size;

    chunk_a_size = 0;
    b_par = get_stack_param(b);
    b_pivot = get_mid(b, b_par);
    while (b_par.max[0] > b_pivot)
    {
        if ((*b)->data > b_pivot)
        {
            push_a(a, b);
            chunk_a_size++;
            b_par.max[0] = get_max(*b);
        }
        rotate_b(b);
    }
    return (chunk_a_size);
}

static int  pivot_push_b(t_stack **a, t_stack **b, int chunk_size)
{
    t_param a_par;
    int     a_pivot;
    int     chunk_b_size;

    chunk_b_size = 0;
    a_par = get_stack_param(a);
    /*a_pivot[0] is the mid of the range of stack a*/
    a_pivot = get_mid(a, a_par);
    /*a_pivot[1] is the half size of stack a*/
    while (a_par.min[0] < a_pivot)
    {
        if ((*a)->data < a_pivot)
        {
            push_b(a, b);
            chunk_b_size++;            
            a_par.max[0] = get_min(*a);
        }
        rotate_a(a);
    }
    return (chunk_b_size);
}

void    quick_sort(t_stack **a, t_stack **b, int chunk_a)
{
    int     i;
    int     chunk_b[500];

    i = -1;
    while (chunk_a > 3)
    {
        if (is_sorted_chunk(a, chunk_a))
            break ;
        chunk_b[++i] = pivot_push_b(a, b, chunk_a);
        chunk_a -= chunk_b[i];
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