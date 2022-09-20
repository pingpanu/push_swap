/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 00:12:09 by user              #+#    #+#             */
/*   Updated: 2022/09/21 00:18:25 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

void	check_swap_a(t_stack **a)
{
    t_stack	*node1;
	t_stack	*node2;

	top_swap(a);
    if (!(*a)->next)
		return ;
	node1 = *a;
	node2 = (*a)->next;
	*a = node2;
	node1->next = node2->next;
	(*a)->next = node1;
}

void	check_swap_b(t_stack **b)
{
	t_stack	*node1;
	t_stack	*node2;

	if (!(*b)->next)
		return ;
	node1 = *b;
	node2 = (*b)->next;
	*b = node2;
	node1->next = node2->next;
	(*b)->next = node1;
}

void	check_swap_ss(t_stack **a, t_stack **b)
{
	top_swap(a);
	top_swap(b);
}