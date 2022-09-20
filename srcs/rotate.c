/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:42:58 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/20 09:42:59 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int	rotate_a(t_stack **a)
{
	rotate_stack(a);
	ft_putendl_fd("ra", 1);
	return (1);
}

int	rotate_b(t_stack **b)
{
	rotate_stack(b);
	ft_putendl_fd("rb", 1);
	return (1);
}

int	rotate_ab(t_stack **a, t_stack **b)
{
	rotate_stack(a);
	rotate_stack(b);
	ft_putendl_fd("rr", 1);
	return (1);
}
