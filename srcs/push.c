/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:46:10 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/06 14:46:12 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*push;

	if (!(*b))
		return ;
	push = *b;
	*b = push->next;
	push->next = NULL;
	ft_lstadd_front(a, push);
	ft_putendl_fd("pa", 1);
}

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*push;

	if (!(*a))
		return ;
	push = *a;
	*a = push->next;
	push->next = NULL;
	ft_lstadd_front(b, push);
	ft_putendl_fd("pb", 1);
}
