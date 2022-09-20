/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:12:26 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/20 10:12:42 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

void	tri_sort(t_stack **a, t_param a_par)
{
	if (check_ascend(a))
		return ;
	if (a_par.max[1] == 1)
		rotate_a(a);
	else if (a_par.max[1] == 2)
		r_rotate_a(a);
	else
		swap_a(a);
	a_par = get_stack_param(a, 0);
	tri_sort(a, a_par);
}

void	sorting_ops(t_stack **a, t_stack **b)
{
	int	a_size;

	if (check_ascend(a))
		return ;
	a_size = ft_lstsize(*a);
	if (a_size == 1)
		return ;
	else if (a_size == 2)
	{
		if (!check_ascend(a))
			swap_a(a);
	}
	else if (a_size == 3)
		tri_sort(a, get_stack_param(a, 0));
	else if (a_size > 3 && a_size <= 50)
		insertion_sort(a, b, 0);
	else
		quick_sort(a, b, a_size);
}
