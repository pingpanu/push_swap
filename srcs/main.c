/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:27:42 by pingpanu          #+#    #+#             */
/*   Updated: 2022/07/14 11:35:38 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
int	main(int argc, char **argv)
{
	//t_stack	*stack;
	char	**nbr;
	int		size;

	if (argc != 1)
	{
		size = 0;
		nbr = check_argvs(argc, argv, &size);
		if (nbr)
		{
			for (int i = 0; nbr[i] != NULL; i++)
				printf("%s\n", nbr[i]);
			/*stack = to_stack(nbr, size);
			if (stack)
			{
				do_swap(stack);
				free(stack);s
				return (0);
			}*/
			return (0);
		}
	}
	ft_putendl_fd("ERROR", 1);
	return (0);
}
