/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argvs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:57:47 by pingpanu          #+#    #+#             */
/*   Updated: 2022/07/14 16:22:30 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	atoi_stack(t_stack *stack, char **argv, int mode);

void	parse_argv(t_stack *stack, int argc, char **argv)
{
	char	**nbr;
	int	mode;

	mode = 0;
	if (argc == 2)
	{
		nbr = ft_split(argv[1]);
		mode = 1;
	}
	else
		nbr = argv;
	stack.size_a = getsize(nbr, mode);
	stack.size_b = stack_size_a;
	stack.a_col = (int *)ft_calloc(sizeof(int),stack.size_a);
	stack.b_col = (int *)ft_calloc(sizeof(int),stack.size_b);
	if (!stack.a_col || !stack.b_col)
		stack = NULL;
	else
		atoi_stack(stack, nbr, mode);
}

static void	atoi_stack(t_stack *stack, char **nbr, int mode)
{
	size_t		col_i;
	size_t		nbr_i;
	unsigned long	buf;
	
	col_i = 0;
	nbr_i = 1;
	if (mode == 1)
		nbr_i = 0;
	while (col_i < stack.size_a - 1)
	{
		stack.a_col[col_i] = nbr[nbr_i];
		col_i++;
		nbr_i++;
	}
}
