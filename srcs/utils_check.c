/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:29:41 by pingpanu          #+#    #+#             */
/*   Updated: 2022/07/25 11:51:14 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checknumeric(int argc, char **argv)
{
	if (argc == 2)
	{
		while (*argv[1])
		{
			if (!ft_isdigit(*argv[1]) && *argv[1] != ' ' && *argv[1] != '-')
				return (0);
			argv[1]++;
		}
	}
	else
	{
		while (argc-- > 1)
		{
			while(*argv[argc])
			{
				if (!ft_isdigit(*argv[argc]) && *argv[argc] != '-')
					return (0);
				argv[argc]++;
			}
		}
	}
	return (1);
}

int		checkvalidint(int argc, char **argv, t_stack *stacks)
{
	
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