/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:47:49 by pingpanu          #+#    #+#             */
/*   Updated: 2022/08/05 17:09:10 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

static void     tri_sort(t_stack **a, t_stack_param a_par)
{
    if (a_par.max[1] == 1)
    {
        if (a_par.min[1] == 3)
        {
            r_rotate_a(a);
            swap_a(a);
        }
        else
            rotate_a(a);
    }
    else if (a_par.min[1] == 3 && a_par.max[1] == 2)
        r_rotate_a(a);
    else if (a_par.min[1] == 2 && a_par.max[3] == 3)
        swap_a(a);
    else
    {
        rotate_a(a);
        swap_a(a);   
    }
}

void     insertion_sort(t_stack **a, t_stack **b, t_stack_param a_par)
{
    if (check_ascend(a) && b == NULL)
        return ;
    if (a_par.min[1] != 1)
    {
        if (a_par.min[1] < (a_par.stack_size / 2))
            r_rotate_a(a); //rra
        else
            rotate_a(a); //ra
    }       
    if (a_par.stack_size == 3)
            tri_sort(a, a_par);
    if (check_ascend(a) && check_descent(b))
        push_a(a, b); //pa
    else
        push_b(a, b); //pb
    a_par = get_stack_param(a);
    insertion_sort(a, b, a_par);
}