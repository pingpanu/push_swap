/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:52:25 by pingpanu          #+#    #+#             */
/*   Updated: 2022/11/04 21:08:32 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

static int	pivot_push_a(t_stack **a, t_stack **b, int chunk_b_size)
{
	t_param	b_par;
	int		b_pivot;
	int		chunk_a_size;
	int		rb;

	chunk_a_size = 0;
	rb = 0;
	b_par = get_stack_param(b, chunk_b_size);
	b_pivot = get_mid(*b, b_par);
	while (b_par.max[0] > b_pivot)
	{
		while ((*b)->data <= b_pivot)
			rb += rotate_b(b);
		chunk_a_size += push_a(a, b);
		b_par = get_stack_param(b, (chunk_b_size - chunk_a_size));
	}
	return (chunk_a_size);
}

static int	pivot_push_b(t_stack **a, t_stack **b, int chunk_a_size)
{
	t_param	a_par;
	int		a_pivot;
	int		chunk_b_size;
	int		ra;

	chunk_b_size = 0;
	ra = 0;
	a_par = get_stack_param(a, chunk_a_size);
	a_pivot = get_mid(*a, a_par);
	while (a_par.min[0] <= a_pivot)
	{
		while ((*a)->data > a_pivot)
			ra += rotate_a(a);
		chunk_b_size += push_b(a, b);
		a_par = get_stack_param(a, (chunk_a_size - chunk_b_size));
	}
	return (chunk_b_size);
}

static void	sort_a_less_3(t_stack **a, t_stack **b)
{
	if (check_ascend(a))
		return ;
	if (ft_lstsize(*a) == 3)
		tri_sort(a, get_stack_param(a, 0));
	else
		insertion_sort(a, b, ft_lstsize(*b));
}

void	quick_sort(t_stack **a, t_stack **b, int chunk_a)
{
	int	i;
	int	chunk_b[500];

	i = -1;
	while (chunk_a > 3)
	{
		if (check_ascend(a))
			break ;
		chunk_b[++i] = pivot_push_b(a, b, chunk_a);
		chunk_a -= chunk_b[i];
	}
	sort_a_less_3(a, b);
	while (i >= 0)
	{
		while (chunk_b[i] > 20)
		{
			chunk_a = pivot_push_a(a, b, chunk_b[i]);
			quick_sort(a, b, chunk_a);
			chunk_b[i] -= chunk_a;
		}
		while (chunk_b[i] > 0)
			chunk_b[i] -= push_back(a, b);
		i--;
	}
}
