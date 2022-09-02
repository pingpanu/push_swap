/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:36:00 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/02 14:18:00 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*To do list
 * 1) Check if argv is equal 1, if yes return error.
 * 2) Check if the struct dont have Nonnumeric character
 * 3) Parse argv to linked list, stop if it have invalid int
 * 4) Check duplicate value in the linked list.
 * 5) Sort the stack by the following rule.
 * 	5.1) Less than 3 use fixed algorithm.
 * 	5.2) Between 4 to 50 use insertion sort.
 * 	5.3) More than 50 use quick sort.
 * 6) End
 */

static void		free_stack(t_stack **a, t_stack **b);

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc != 1)
	{
		a = NULL;
		b = NULL;
		if (argc == 2)
		{
			if (!argv_split(argv + 1, &a))
				error_exit(&a, &b);
		}
		else
		{
			if (!argv_nor(argc - 1, argv + 1, &a))
				error_exit(&a, &b);
		}
		sorting_ops(&a, &b);
		free_stack(&a, &b);
		exit(0);
	}
}

void	error_exit(t_stack **a, t_stack **b)
{
	free_stack(a, b);
	ft_putendl_fd("Error", 2);
	exit(1);
}

static void	free_stack(t_stack **a, t_stack **b)
{
	ft_lstclear(a);
	ft_lstclear(b);
	a = NULL;
	b = NULL;
}
