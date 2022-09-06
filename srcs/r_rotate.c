/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:47:11 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/06 14:47:14 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	r_rotate_stack(t_stack **lst)
{
	t_stack	*temp;
	t_stack	*cursor;

	if (!(*lst)->next)
		return ;
	cursor = *lst;
	while (cursor->next->next != NULL)
		cursor = cursor->next;
	temp = cursor->next;
	cursor->next = NULL;
	ft_lstadd_front(lst, temp);
}

void	r_rotate_a(t_stack **a)
{
	r_rotate_stack(a);
	ft_putendl_fd("rra", 1);
}

void	r_rotate_b(t_stack **b)
{
	r_rotate_stack(b);
	ft_putendl_fd("rrb", 1);
}

void	r_rotate_ab(t_stack **a, t_stack **b)
{
	r_rotate_stack(a);
	r_rotate_stack(b);
	ft_putendl_fd("rrr", 1);
}
