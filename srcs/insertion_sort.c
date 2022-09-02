/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:47:49 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/02 14:34:31 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

static void     tri_sort(t_stack **a, t_stack_param a_par)
{
    if (a_par.max[1] == 2)
    {
        rotate_a(a);
        if (a_par.min[1] == 1)
            swap_a(a);
    }
    else if (a_par.min[1] == 2)
    {
        if (a_par.max[1] == 3)
            swap_a(a);
        else
            r_rotate_a(a);
    }
    else
    {
        r_rotate_a(a);
        swap_a(a);   
    }
}

void     insertion_sort(t_stack **a, t_stack **b)
{
    size_t  size_b;

    size_b = 0;
    if (check_ascend(a) && b == NULL || a == NULL)
        return ;
    while (a_par.stack_size > 3)
    {
        push_min(a, b, a_par);
        a_par = get_stack_param(a);
        size_b++;
    }
    if (a_par.stack_size == 3)
        tri_sort(a, a_par);
    while (size_b > 0)
    {
        push_a(a, b);
        size_b--;
    }
    //insertion_sort(a, b, a_par);
}