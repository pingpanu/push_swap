/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:47:49 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/17 22:58:46 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

/*  consider how actual insertion_sort work, this thing should be called bubble_sort  */
/*  but push_swap limitation make bubble sort as fast as insertion_sort               */

static void	a_max_to_last(t_stack **a, t_param *a_par)
{
	int		a_mid;

	a_mid = (a_par->stack_size / 2) + 1;
	while (a_par->max[1] < a_par->stack_size)
	{
		if (a_par->max[1] < a_mid)
		{
			rotate_a(a);
			a_par->max[1]--;
			if (a_par->max[1] < 1)
				a_par->max[1] = a_par->stack_size;
		}
		else
		{
			r_rotate_a(a);
			a_par->max[1]++;
		}
	}
}

static int	check_and_swap(t_stack **a, t_stack **b, t_param *a_par)
{
	if (check_ascend(a))
		return (0);
	insert_swap(a, b);
	if (check_ascend(a))
		return (0);
	push_b(a, b);
	a_par->stack_size--;
	return (1);
}

void	insertion_sort(t_stack **a, t_stack **b, int b_size)
{
	t_param	a_par;
	int		b_limit;

	a_par = get_stack_param(a, 0);
	if (a_par.max[1] < a_par.stack_size)
		a_max_to_last(a, &a_par);
	if (check_ascend(a))
		return ;
	while (a_par.stack_size > 3)
	{
		if (!check_and_swap(a, b, &a_par))
			break ;
	}
	if (!check_ascend(a))
		insert_swap(a, b);
	b_limit = ft_lstsize(*b) - b_size;
	while (b_limit > 0)
	{
		push_back(a, b);
		b_limit--;
	}
}