/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:27:42 by pingpanu          #+#    #+#             */
/*   Updated: 2022/07/07 22:50:19 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;
	char	**nbr;
	int		size;

	if (argc != 1)
	{
		size = 0;
		nbr = check_argvs(argc, argv, &size);
		if (nbr)
		{
			stack = to_stack(nbr, size);
			if (stack)
			{
				do_swap(stack);
				free(stack);
				return (0);
			}
		}
	}
	ft_putendl_fd("ERROR");
	return (0);
}
