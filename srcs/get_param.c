/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:00:32 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/09 15:08:07 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stack *lst)
{
	int	min;

	min = INT_MAX;
	while (lst != NULL)
	{
		if (min > lst->data)
			min = lst->data;
		lst = lst->next;
	}
	return (min);
}

int	get_max(t_stack *lst)
{
	int	max;

	max = INT_MIN;
	while (lst != NULL)
	{
		if (max < lst->data)
			max = lst->data;
		lst = lst->next;
	}
	return (max);
}

static int	get_pos(t_stack *lst, int nbr)
{
	int	pos;

	pos = 1;
	while (lst != NULL)
	{
		if (lst->data == nbr)
			break ;
		pos++;
		lst = lst->next;
	}
	return (pos);
}

t_param	get_stack_param(t_stack **lst)
{
	t_param	param;

	param.stack_size = ft_lstsize(*lst);
	param.min[0] = get_min(*lst);
	param.max[0] = get_max(*lst);
	param.min[1] = get_pos(*lst, param.min[0]);
	param.max[1] = get_pos(*lst, param.max[0]);
	return (param);
}
