/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:47:49 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/02 16:03:35 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

static void	check_push(t_stack **a, t_stack **b)
{
	if ((*a)->data > (*a)->next->data)
		swap_a(a);
	push_b(a, b);
}

static void	check_ab_stack(t_stack **a, t_stack **b, t_param a_par)
{
	if ((*a)->data > (*a)->next->data)
		swap_ab(a, b);
	else
		swap_b(b);
	tri_sort(a, a_par);
}

void	insertion_sort(t_stack **a, t_stack **b)
{
	t_param	a_par;
	t_param	b_par;

	a_par = get_stack_param(a);
	while (a_par.max[2] < a_par.min[2])
		rearrange(a, a_par);
	while (a_par.stack_size > 3)
	{
		check_push(a, b);
		a_par.stack_size--;
	}
	b_par = get_stack_param(b);
	if (check_descend(b) == 1)
		tri_sort(a, a_par);
	else
		check_ab_stack(a, b, a_par);
	while (b_par.stack_size > 0)
	{
		push_back(a, b, b_par);
		b_par.stack_size--;
	}
}
