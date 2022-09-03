/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:09:54 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/03 14:36:41 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_stack **lst)
{
	t_stack	*temp;

	if (!(*lst)->next)
		return ;
	temp = *lst;
	*lst = temp->next;
	temp->next = NULL;
	ft_lstadd_back(lst, temp);
}

void	rotate_a(t_stack **a)
{
	rotate_stack(a);
	ft_putendl_fd("ra", 1);
}

void	rotate_b(t_stack **b)
{
	rotate_stack(b);
	ft_putendl_fd("rb", 1);
}

void	rotate_ab(t_stack **a, t_stack **b)
{
	rotate_stack(a);
	rotate_stack(b);
	ft_putendl_fd("rr", 1);
}
