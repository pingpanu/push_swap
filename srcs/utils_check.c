/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:13:41 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/20 10:14:33 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checknumeric(char *str)
{
	while (*str)
	{
		if ((*str >= 9 && *str <= 13) || *str == 32)
			str++;
		else if (!ft_isdigit(*str) && *str != '-')
			return (0);
		str++;
	}
	return (1);
}

int	checkdup(t_stack *lst)
{
	t_stack	*check;

	check = ft_lstlast(lst);
	while (lst != check)
	{
		if (lst->data == check->data)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	check_ascend(t_stack **lst)
{
	t_stack	*cursor;

	if (ft_lstsize(*lst) == 0)
		return (0);
	cursor = *lst;
	while (cursor->next != NULL)
	{
		if (cursor->data > cursor->next->data)
			return (0);
		cursor = cursor->next;
	}
	return (1);
}
