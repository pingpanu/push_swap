/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:08:26 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/20 10:13:07 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	push_a(t_stack **a, t_stack **b)
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

int	push_b(t_stack **a, t_stack **b)
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
