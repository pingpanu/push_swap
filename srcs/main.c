/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:27:42 by pingpanu          #+#    #+#             */
/*   Updated: 2022/07/07 20:36:14 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/*main will do the following things
 * check if argv worked
 * check the array of ints
 * if array of ints is good, start push_swaps
 */

static void	check_

int	main(int argc, char **argv)
{
	t_stack	*stack;
	char	**nbr;

	if (argc == 1)
	{
		ft_putendl_fd("ERROR", 1);
		return (0);
	}
	stack = ft_malloc(sizeof(t_stack));
	if (!stack)
	{
		ft_putendl_fd("ERROR", 1);
		return (0);
	}
	if (argc == 2)
	{
		nbr = ft_split(argv[1], ' ');
		stack = to_stack(nbr, 1);
	}
	else
	{
		nbr = argv;
		stack = to_stack(nbr, 0);
	}
	do_swap(stack);
	free(stack);
	return (0);
}
