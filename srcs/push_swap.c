/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:36:00 by pingpanu          #+#    #+#             */
/*   Updated: 2022/07/25 11:50:54 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*To do list
 * 1) Check if argv is equal 1, if yes return error.
 * 2) Check if the struct dont have Nonnumeric character
 * 3) Parse argv to linked list, stop if it have invalid int (less than -2147483648 or more than 2147483647)
 * 4) Check duplicate value in the linked list.
 * 5) Sort the stack by the following rule.
 * 	5.1) Less than 5 use fixed algorithm.
 * 	5.2) More than 5 but less than 100 use insertion sort.
 * 	5.3) More or equal 100 use quick sort.
 * 6) End
 */

static void		free_stack(t_stack *stacks);
static int		check_stack(t_stack *stacks);

int	push_swap(int argc, char **argv)
{
	t_stack	*stacks;

	if (argc != 1)
	{
		if (!checknumeric(argc, argv))
		{
			ft_putendl_fd("Error", 2);
			exit (1);
		}
		stacks->a = NULL;
		stacks->b = NULL;
		if (!checkvalidint(argc, argv, &stacks))
			error_exit(1);
		if (!check_stack(&stacks))
			swap_sort(&stacks);
		free_stack(&stacks);
	}
	exit (1);
}

void	error_exit(t_stack *stacks)
{
	free_stack(stacks);
	ft_putendl_fd("Error", 2);
	exit (1);
}

static void		free_stack(t_stack *stacks)
{
	ft_lstclear(stacks->a, void);
	ft_lstclear(stacks->b, void);
	stacks->a = NULL;
	stacks->b = NULL;
}

static int		check_stack(t_stack *stacks);