/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:43:30 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/20 09:43:32 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int	r_rotate_a(t_stack **a)
{
	r_rotate_stack(a);
	ft_putendl_fd("rra", 1);
	return (1);
}

int	r_rotate_b(t_stack **b)
{
	r_rotate_stack(b);
	ft_putendl_fd("rrb", 1);
	return (1);
}

int	r_rotate_ab(t_stack **a, t_stack **b)
{
	r_rotate_stack(a);
	r_rotate_stack(b);
	ft_putendl_fd("rrr", 1);
	return (1);
}
