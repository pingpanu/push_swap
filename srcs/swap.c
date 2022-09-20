/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:09:22 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/20 10:09:25 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int	swap_a(t_stack **a)
{
	top_swap(a);
	ft_putendl_fd("sa", 1);
	return (1);
}

int	swap_b(t_stack **b)
{
	top_swap(b);
	ft_putendl_fd("sb", 1);
	return (1);
}

int	swap_ab(t_stack **a, t_stack **b)
{
	top_swap(a);
	top_swap(b);
	ft_putendl_fd("ss", 1);
	return (1);
}
