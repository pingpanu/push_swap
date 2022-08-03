/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:48:54 by user              #+#    #+#             */
/*   Updated: 2022/08/03 15:51:58 by pingpanu         ###   ########.fr       */
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

void     tri_sort(t_stack **lst, t_stack_param param)
{
	/*to do list
	 * 1) compare 1st and 2nd node
	 * 	1.1) 1st > 2nd --> sa
	 * 	1.2) 1st < 2nd --> to 2)
	 * 2) compare 2nd and 3th node
	 * 	2.1) 2nd > 3rd --> rra
	 * 	2.2) 2nd < 3rd --> end
	 */
}

void    sorting_ops(t_stack **a, t_stack **b)
{
    t_stack_param   a_param;

    a_param = get_stack_param(a);
    if (a_param.stack_size == 1)
        return ;
    else if (a_param.stack_size == 2)
        twin_sort(a);
    else if (a_param.stack_size == 3) //insetion sort
        tri_sort(a, a_param);
    else if (a_param.stack_size > 3 && a_param.stack_size < 100)
        insert_sort(a, b);
    else
        quick_sort(a, b); 
}
