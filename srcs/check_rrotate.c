/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 00:19:08 by user              #+#    #+#             */
/*   Updated: 2022/09/21 00:21:19 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

void	check_rrotate_a(t_stack **a)
{
    t_stack	*temp;
	t_stack	*cursor;

	if (!(*a)->next)
		return ;
	cursor = *a;
	while (cursor->next->next != NULL)
		cursor = cursor->next;
	temp = cursor->next;
	cursor->next = NULL;
	ft_lstadd_front(a, temp);
}

void	check_rrotate_b(t_stack **b)
{
    t_stack	*temp;
	t_stack	*cursor;

	if (!(*b)->next)
		return ;
	cursor = *b;
	while (cursor->next->next != NULL)
		cursor = cursor->next;
	temp = cursor->next;
	cursor->next = NULL;
	ft_lstadd_front(b, temp);
}

void	check_rrotate_r(t_stack **a, t_stack **b)
{
	r_rotate_stack(a);
	r_rotate_stack(b);
}