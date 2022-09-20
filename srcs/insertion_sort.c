/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:39:24 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/20 10:30:00 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

static void	a_max_to_last(t_stack **a, t_param *a_par)
{
	int		a_mid;

	a_mid = (a_par->stack_size / 2) + 1;
	while (a_par->max[1] < a_par->stack_size)
	{
		if (a_par->max[1] < a_mid)
		{
			a_par->max[1] -= rotate_a(a);
			if (a_par->max[1] < 1)
				a_par->max[1] = a_par->stack_size;
		}
		else
			a_par->max[1] += r_rotate_a(a);
	}
}

static int	max_ascend(t_stack **a, t_param a_par)
{
	int		ascend;

	ascend = get_ascend_stack(a);
	if (a_par.max[1] == ascend && ascend == 1)
		return (1);
	if (a_par.max[1] == ascend && a_par.min[0] > ascend)
		return (1);
	return (0);
}

static int	check_and_swap(t_stack **a, t_stack **b, t_param *a_par)
{
	if (check_ascend(a))
		return (0);
	insert_swap(a, b);
	if (check_ascend(a))
		return (0);
	a_par->stack_size -= push_b(a, b);
	return (1);
}

void	insertion_sort(t_stack **a, t_stack **b, int b_size)
{
	t_param	a_par;
	t_param	b_par;
	int		b_limit;

	a_par = get_stack_param(a, 0);
	if (max_ascend(a, a_par))
		a_max_to_last(a, &a_par);
	if (check_ascend(a))
		return ;
	while (a_par.stack_size > 3)
	{
		if (!check_and_swap(a, b, &a_par))
			break ;
	}
	if (!check_ascend(a) && a_par.stack_size == 3)
		tri_sort(a, get_stack_param(a, 0));
	b_limit = ft_lstsize(*b) - b_size;
	b_par = get_stack_param(b, 0);
	if ((*a)->data < b_par.max[0])
		b_limit += push_b(a, b);
	while (b_limit > 0)
		b_limit -= push_back(a, b);
}
