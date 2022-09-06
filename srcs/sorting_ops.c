/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:47:34 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/06 16:07:21 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

void	tri_sort(t_stack **a, t_param a_par)
{
	if (a_par.max[1] == 1)
	{
		rotate_a(a);
		if ((*a)->data > (*a)->next->data)
			swap_a(a);
	}
	else if (a_par.max[1] == 2)
	{
		r_rotate_a(a);
		if ((*a)->data > (*a)->next->data)
			swap_a(a);
	}
	else
		swap_a(a);
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
		tri_sort(a, get_stack_param(a));
	else if (a_size > 3 && a_size <= 50)
		insertion_sort(a, b);
	else
		quick_sort(a, b, a_size);
}
