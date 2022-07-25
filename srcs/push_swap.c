/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:36:00 by pingpanu          #+#    #+#             */
/*   Updated: 2022/07/25 17:03:32 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*To do list
 * 1) Check if argv is equal 1, if yes return error.
 * 2) Check if the struct dont have Nonnumeric character
 * 3) Parse argv to linked list, stop if it have invalid int
 * 4) Check duplicate value in the linked list.
 * 5) Sort the stack by the following rule.
 * 	5.1) Less than 5 use fixed algorithm.
 * 	5.2) More than 5 but less than 100 use insertion sort.
 * 	5.3) More or equal 100 use quick sort.
 * 6) End
 */

static void		free_stack(t_stack *a, t_stack *b);
static int		check_sort(t_stack *stack);

int		push_swap(int argc, char **argv)
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
				error_exit(a, b);
		}
		else
		{
			if (!argv_nor(argc - 1, argv + 1, &a))
				error_exit(a, b);
		}
		/*if (!check_sort(a))
			swap_sort(&a, &b);*/
		free_stack(a, b);
		exit (0);
	}
}

void	error_exit(t_stack *a, t_stack *b)
{
	free_stack(a, b);
	ft_putendl_fd("Error", 2);
	exit(1);
}

static void		free_stack(t_stack *a, t_stack *b)
{
	ft_lstclear(a, free);
	ft_lstclear(b, free);
	a = NULL;
	b = NULL;
}

/*static int		check_sort(t_stack *a)
{
	while (a != NULL)
	{
		if (a->next != NULL)
			if (a->data > a->next->data)
				return (0);
		a = a->next;
	}
	return (1);
}*/