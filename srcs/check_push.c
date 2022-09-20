/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 00:04:21 by user              #+#    #+#             */
/*   Updated: 2022/09/21 00:13:19 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check_push_a(t_stack **a, t_stack **b)
{
	t_stack	*push;

	if (!(*b))
		return ;
	push = *b;
	*b = push->next;
	push->next = NULL;
	ft_lstadd_front(a, push);
}

void	check_push_b(t_stack **a, t_stack **b)
{
	t_stack	*push;

	if (!(*a))
		return ;
	push = *a;
	*a = push->next;
	push->next = NULL;
	ft_lstadd_front(b, push);
}