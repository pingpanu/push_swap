/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:36:00 by pingpanu          #+#    #+#             */
/*   Updated: 2022/07/19 11:54:57 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*To do list
 * 1) Check if argv is equal 1, if yes return error.
 * 2) Check if argv have only digit, if no return error.
 * 3) Parse argv to struct.
 * 4) Check if struct dont have the following.
 * 	4.1) Number larger than MAX_INT or smaller than MIN_INT
 * 	4.2) Duplicate value
 * 5) Sort the stack by the following rule.
 * 	5.1) Less than 5 use fixed algorithm.
 * 	5.2) More than 5 but less than 100 use insertion sort.
 * 	5.3) More or equal 100 use insertionn sort.
 * 6) End
 */

/*puterr_mes is a function to show error message on screen*/
static void	puterr_mes(char *message)
{
	ft_putenld(message, 1);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	int		mode;

	if (argc != 1)
	{
		mode = 1;
		if (argc == 2)
			mode = 0;
		if (check_argvs(mode, argv))
		{
			stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
			if (!stack)
				puterr_mes("Memory allocation failed");
			parse_argv(stack, argv, mode);
			if (check_stack(stack) == 2)
				puterr_mes("Have duplicate value");
			else if (check_stack(stack) == 1)
				puterr_mes("Value not within int range");
			pushswap(stack);
			return (0);
		}
		puterr_mes("Arguments have nonnumeric characters");
	}
	puterr_mes("Too few arguments");
}
