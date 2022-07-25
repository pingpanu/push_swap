/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:29:41 by pingpanu          #+#    #+#             */
/*   Updated: 2022/07/25 17:17:37 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checknumeric(char *str)
{
	while(*str)
	{
		if ((*str >= 9 && *str <= 13) || *str == 32)
			str++;
		else if (!ft_isdigit(*str) && *str != '-')
			return (0);
		str++;
	}
	return (1);
}

int		checkvalidint(t_stack *temp, char *nbr)
{
	char	*check;

	check = ft_itoa(temp->data);
	if (!check || ft_strcmp(check, nbr) != 0)
		return (0);
}

/*for test only
#include <stdio.h>
int	main(int argc, char **argv)
{
	if (argc != 1)
	{
		if (checknumeric(argc, argv) == 1)
			printf("argvs are numeric");
		else
			printf("argvs aren't numeric");
		return (0);
	}
	return (0);
}*/