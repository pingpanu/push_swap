/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 00:16:30 by user              #+#    #+#             */
/*   Updated: 2022/09/21 00:18:53 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

void	check_rotate_a(t_stack **a)
{
    t_stack	*temp;

	if (!(*a)->next)
		return ;
	temp = *a;
	*a = temp->next;
	temp->next = NULL;
	ft_lstadd_back(a, temp);
}

void    check_rotate_b(t_stack **b)
{
    t_stack	*temp;

	if (!(*b)->next)
		return ;
	temp = *b;
	*b = temp->next;
	temp->next = NULL;
	ft_lstadd_back(b, temp);
}

void	check_rotate_r(t_stack **a, t_stack **b)
{
	rotate_stack(a);
	rotate_stack(b);
}