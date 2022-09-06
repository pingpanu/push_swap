/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:47:49 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/06 20:35:57 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

static void	a_max_to_last(t_stack **a, t_param *a_par)
{
	int		a_mid;

	a_mid = a_par->stack_size / 2;
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

static void	insert_swap(t_stack **a, t_stack **b)
{
	int		need_sa;
	int		need_sb;

	need_sa = 0;
	need_sb = 0;
	if ((*a)->data > (*a)->next->data)
		need_sa = 1;
	if ((*b)->next != NULL && (*b)->data < (*b)->next->data)
		need_sb = 1;
	if (need_sa == 1 && need_sb == 0)
		swap_a(a);
	else if (need_sa == 0 && need_sb == 1)
		swap_b(a);
	else if (need_sa == 1 && need_sb == 1)
		swap_ab(a, b);
	else
		return ;
}

static void	push_back(t_stack **a, t_stack **b, t_param b_par)
{
	int		b_mid;

	if (b_par.max[1] != 1)
	{
		b_mid = b_par.stack_size / 2;
		while (b_par.max[1] > 1)
		{
			if (b_par.max[1] < b_mid)
			{
				rotate_b(b);
				b_par.max[1]--;
			}
			else
			{
				r_rotate_b(b);
				b_par.max[1]++;
				if (b_par.max[1] > b_par.stack_size)
					b_par.max[1] = 1;
			}
		}
	}
	push_a(a, b);
}

void	insertion_sort(t_stack **a, t_stack **b)
{
	t_param	a_par;
	t_param	b_par;

	a_par = get_stack_param(a);
	if (a_par.max[2] < a_par.stack_size)
		a_max_to_last(a, &a_par);
	while (a_par.stack_size > 3)
	{
		insert_swap(a, b);
		push_a(a, b);
		a_par.stack_size--;
	}
	insert_swap(a, b);
	b_par = get_stack_param(b);
	while (b_par.stack_size > 0)
	{
		push_back(a, b, b_par);
		if ((*a)->data > (*a)->next->data)
			swap_a(a);
		b_par = get_stack_param(b);
	}
}
