/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:48:54 by user              #+#    #+#             */
/*   Updated: 2022/08/02 15:25:38 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

static void     twin_sort(t_stack **lst)
{
    if (!check_ascend(*lst))
        swap_a(lst);
    else
        return ;
}

void     tri_sort(t_stack **lst, t_stack_param params)
{

}

void    sorting_ops(t_stack **a, t_stack **b)
{
    t_stack_param   a_param;

    a_param = get_stack_param(a);
    if (a_param.stack_size == 1)
        return ;
    else if (a_param.stack_size == 2)
        twin_sort(a);
    else if (a_param.stack_size == 3)
        tri_sort(a, a_param);
    else if (a_param.stack_size > 3 && a_param.stack_size < 100)
        insert_sort(a, b);
    else
        quick_sort(a, b); 
}