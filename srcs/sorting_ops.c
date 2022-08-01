/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:48:54 by user              #+#    #+#             */
/*   Updated: 2022/08/01 22:55:59 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

void    sorting_ops(t_stack **a, t_stack **b)
{
    t_stack_param   *a_param;
    t_stack_param   *b_param;

    a_param = get_stack_param(a);
    if (a_param.stack_size == 1)
        return ;
    else if (a_param.stack_size == 2)
        twin_sort(t_stack **a);
    else if (a_param.stack_size == 3)
        tri_sort(t_stack **a);
    else if (a_param > 3 && a_param < 100)
        insert_sort(t_stack **a, t_stack **b);
    else
        quick_sort(t_stack **a, t_stack **b); 
}