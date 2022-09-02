/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:57:47 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/02 14:13:52 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	valid_integer(char *nbr, t_stack **a)
{
	t_stack	*temp;
	char	*check;

	if (!checknumeric(nbr))
		return (0);
	temp = ft_lstnew(ft_atoi(nbr));
	check = ft_itoa(temp->data);
	if (!temp || ft_strcmp(check, nbr) != 0)
	{
		free(check);
		return (0);
	}
	free(check);
	ft_lstadd_back(a, temp);
	return (1);
}

static void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	argv_split(char **arr, t_stack **a)
{
	int	i;

	arr = ft_split(arr[0], ' ');
	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
	{
		if (!valid_integer(arr[i], a))
		{
			free_array(arr);
			return (0);
		}
		if (!checkdup(*a))
		{
			free_array(arr);
			return (0);
		}
		i++;
	}
	free_array(arr);
	return (1);
}

int	argv_nor(int size, char **arr, t_stack **a)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ft_strlen(arr[i]) == 0)
			i++;
		if (!valid_integer(arr[i], a))
			return (0);
		if (!checkdup(*a))
			return (0);
		i++;
	}
	return (1);
}
