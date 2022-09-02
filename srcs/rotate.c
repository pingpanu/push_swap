/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:12:48 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/02 14:50:41 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_stack **lst)
{
	t_stack	*temp;
	t_stack *cursor;

	if (!(*lst)->next)
		return ;
	cursor = *lst;
	while (cursor->next->next != NULL)
		cursor = cursor->next;
	temp = cursor->next;
	cursor->next = NULL;
	ft_lstadd_front(lst, temp);
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