/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:29:41 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/02 13:56:36 by pingpanu         ###   ########.fr       */
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
	if (lst == NULL)
		return (0);
	while (*lst != NULL)
	{
		if ((*lst)->next != NULL)
		{
			if ((*lst)->data > (*lst)->next->data)
				return (0);
		}
		*lst = (*lst)->next;
	}
	return (1);
}

int	check_descend(t_stack **lst)
{
	if (lst == NULL)
		return (0);
	while (*lst != NULL)
	{
		if ((*lst)->next != NULL)
		{
			if ((*lst)->data < (*lst)->next->data)
				return (0);
		}
		*lst = (*lst)->next;
	}
	return (1);
}
