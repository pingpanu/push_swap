/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:06:38 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/17 21:55:10 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

int  get_mid(t_stack *lst, t_param par)
{
    int     mid;
	int		cur;

    mid = (par.max[0] + par.min[0]) / 2;
    cur = lst->data;
    while (lst != NULL)
    {
        if (ft_abs(mid - lst->data) < ft_abs(mid - cur))
            cur = lst->data;
        lst = lst->next; 
    }
	if (cur != (float)cur)
		cur += 0.5;
    return (cur);
}

void	push_back(t_stack **a, t_stack **b)
{
	t_param b_par;
	int		b_mid;

	b_par = get_stack_param(b, 0);
	b_mid = (b_par.stack_size / 2) + 1;
	while (b_par.max[1] > 1)
	{
		if (b_par.max[1] <= b_mid)
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
	push_a(a, b);
	if ((*a)->data > (*a)->next->data)
		swap_a(a);
}

void	insert_swap(t_stack **a, t_stack **b)
{
	int		need_sa;
	int		need_sb;

	need_sa = 0;
	need_sb = 0;
	if ((*a)->data > (*a)->next->data)
		need_sa = 1;
	if (ft_lstsize(*b) > 1 && (*b)->data < (*b)->next->data)
		need_sb = 1;
	if (need_sa == 1 && need_sb == 0)
		swap_a(a);
	else if (need_sa == 0 && need_sb == 1)
		swap_b(b);
	else if (need_sa == 1 && need_sb == 1)
		swap_ab(a, b);
	else
		return ;
}