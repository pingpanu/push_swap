/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:46:10 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/19 12:35:04 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		push_a(t_stack **a, t_stack **b)
{
	t_stack	*push;

	if (!(*b))
		return (0);
	push = *b;
	*b = push->next;
	push->next = NULL;
	ft_lstadd_front(a, push);
	ft_putendl_fd("pa", 1);
	return (1);
}

int		push_b(t_stack **a, t_stack **b)
{
	t_stack	*push;

	if (!(*a))
		return (0);
	push = *a;
	*a = push->next;
	push->next = NULL;
	ft_lstadd_front(b, push);
	ft_putendl_fd("pb", 1);
	return (1);
}