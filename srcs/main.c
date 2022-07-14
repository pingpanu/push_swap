/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:27:42 by pingpanu          #+#    #+#             */
/*   Updated: 2022/07/14 15:56:53 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*to do list
 * 1) parse argv to t_stack, if nbr is not in int size, return null
 * 2) check t_stack int array
 * 3) if t_stack is good, start push_swap, if not free t_stack and exit
 * 4) end 
 */
int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc != 1)
	{
		size = 0;
		parse_argv(t_stack, argc, argv);
		if(!check_stack(t_stack))
		{
			free(t_stack);
			ft_putendl_fd("ERROR",1)
		}
		else
			pushswap(t_stack);
		return (0);
	}
	ft_putendl_fd("ERROR", 1);
	return (0);
}
