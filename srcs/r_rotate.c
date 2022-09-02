/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:09:54 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/02 14:52:34 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	r_rotate_stack(t_stack **lst)
{
	t_stack	*temp;

	if (!(*lst)->next)
		return ;
	temp = *lst;
	*lst = temp->next;
	temp->next = NULL;
	ft_lstadd_back(lst, temp);
}

void	r_rotate_a(t_stack **a)
{
	r_rotate_stack(a);
	ft_putendl_fd("rra", 1);
}

void	r_rotate_b(t_stack **b)
{
	r_rotate_stack(b);
	ft_putendl_fd("rrb", 1);
}

void	r_rotate_ab(t_stack **a, t_stack **b)
{
	r_rotate_stack(a);
	r_rotate_stack(b);
	ft_putendl_fd("rrr", 1);
}