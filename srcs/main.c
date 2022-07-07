/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:27:42 by pingpanu          #+#    #+#             */
/*   Updated: 2022/07/07 22:01:49 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	//t_stack	*stack;
	char	**nbr;
	int		size;

	int		i = 0;

	if (argc == 1)
	{
		//ft_putendl_fd("ERROR", 1);
		printf("Error\n");
		return (0);
	}
	else
	{
		size = 0;
		nbr = check_argvs(argc, argv, &size);
	}
	if (!nbr)
	{
		//ft_putendl_fd("ERROR", 1);
		printf("Error\n");
		return (0);
	}
	while (nbr[i++])
		printf("%s\n", nbr[i]);
	printf("size of nbr is %d\n", size);
	/*stack = to_stack(nbr, size);
	do_swap(stack);
	free(stack);*/
	return (0);
}
