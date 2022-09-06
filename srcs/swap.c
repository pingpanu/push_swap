/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:48:06 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/06 14:48:07 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	top_swap(t_stack **lst)
{
	t_stack	*node1;
	t_stack	*node2;

	if (!(*lst)->next)
		return ;
	node1 = *lst;
	node2 = (*lst)->next;
	*lst = node2;
	node1->next = node2->next;
	(*lst)->next = node1;
}

void	swap_a(t_stack **a)
{
	top_swap(a);
	ft_putendl_fd("sa", 1);
}

void	swap_b(t_stack **b)
{
	top_swap(b);
	ft_putendl_fd("sb", 1);
}

void	swap_ab(t_stack **a, t_stack **b)
{
	top_swap(a);
	top_swap(b);
	ft_putendl_fd("ss", 1);
}
