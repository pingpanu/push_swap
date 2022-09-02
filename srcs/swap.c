/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 22:50:34 by user              #+#    #+#             */
/*   Updated: 2022/09/02 13:58:15 by pingpanu         ###   ########.fr       */
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
