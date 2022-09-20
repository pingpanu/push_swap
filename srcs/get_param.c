/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:49:15 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/20 10:16:48 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stack *lst, int n)
{
	int	min;

	min = INT_MAX;
	while (lst != NULL && n > 0)
	{
		if (min > lst->data)
			min = lst->data;
		lst = lst->next;
		n--;
	}
	return (min);
}

int	get_max(t_stack *lst, int n)
{
	int	max;

	max = INT_MIN;
	while (lst != NULL && n > 0)
	{
		if (max < lst->data)
			max = lst->data;
		lst = lst->next;
		n--;
	}
	return (max);
}

static int	get_pos(t_stack *lst, int nbr, int n)
{
	int	pos;

	pos = 1;
	while (lst != NULL && n > 0)
	{
		if (lst->data == nbr)
			break ;
		pos++;
		lst = lst->next;
		n--;
	}
	return (pos);
}

t_param	get_stack_param(t_stack **lst, int limit)
{
	t_param	param;

	if (limit != 0)
		param.stack_size = limit;
	else
	{
		param.stack_size = ft_lstsize(*lst);
		limit = param.stack_size;
	}
	param.min[0] = get_min(*lst, limit);
	param.max[0] = get_max(*lst, limit);
	param.min[1] = get_pos(*lst, param.min[0], limit);
	param.max[1] = get_pos(*lst, param.max[0], limit);
	return (param);
}
