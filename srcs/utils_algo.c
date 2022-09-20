/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:09:38 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/20 10:11:18 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

int	get_mid(t_stack *lst, t_param par)
{
	float	mid;
	int		cur;

	mid = (par.max[0] + par.min[0]) / 2;
	if ((int)mid != mid)
		mid += 0.5;
	cur = lst->data;
	while (lst != NULL)
	{
		if (ft_abs(mid - lst->data) < ft_abs(mid - cur))
			cur = lst->data;
		lst = lst->next;
	}
	return (cur);
}

int	push_back(t_stack **a, t_stack **b)
{
	t_param	b_par;
	int		b_mid;

	b_par = get_stack_param(b, 0);
	b_mid = (b_par.stack_size / 2) + 1;
	while (b_par.max[1] > 1)
	{
		if (b_par.max[1] <= b_mid)
			b_par.max[1] -= rotate_b(b);
		else
		{
			b_par.max[1] += r_rotate_b(b);
			if (b_par.max[1] > b_par.stack_size)
				b_par.max[1] = 1;
		}
	}
	push_a(a, b);
	if ((*a)->data > (*a)->next->data)
		swap_a(a);
	return (1);
}
