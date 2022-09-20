/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:59:28 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/20 22:43:42 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	free_stack(t_stack **a, t_stack **b);

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (1);
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
	checker_sort(&a, &b);
	free_stack(&a, &b);
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
