/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:02:40 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/20 22:52:40 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "operation.h"
#include <stdio.h>

static int	check_cmd(char *cmd, t_stack **a, t_stack **b)
{
	printf("%s",cmd);
	if (ft_strcmp(cmd, "pa\n") == 0)
		return (push_a(a, b));
	else if (ft_strcmp(cmd, "pb\n") == 0)
		return (push_b(a, b));
	else if (ft_strcmp(cmd, "sa\n") == 0)
		return (swap_a(a));
	else if (ft_strcmp(cmd, "sb\n") == 0)
		return (swap_b(b));
	else if (ft_strcmp(cmd, "ss\n") == 0)
		return (swap_ab(a, b));
	else if (ft_strcmp(cmd, "ra\n") == 0)
		return (rotate_a(a));
	else if (ft_strcmp(cmd, "rb\n") == 0)
		return (rotate_b(a));
	else if (ft_strcmp(cmd, "rr\n") == 0)
		return (rotate_ab(a, b));
	else if (ft_strcmp(cmd, "rra\n") == 0)
		return (r_rotate_a(a));
	else if (ft_strcmp(cmd, "rrb\n") == 0)
		return (r_rotate_b(b));
	else if (ft_strcmp(cmd, "rrr\n") == 0)
		return (r_rotate_ab(a, b));
	else 
		return (0);
}

void	checker_sort(t_stack **a, t_stack **b)
{
	char	*cmd;

	while (1)
	{
		cmd = get_next_line(STDIN_FILENO);
		if (cmd == NULL)
			break ;
		if (!check_cmd(cmd, a, b))
			error_exit(a, b);
		free(cmd);
	}
	if (!check_ascend(a) && ft_lstsize(*b) == 0)
		ft_putendl_fd("KO", 1);
	else
		ft_putendl_fd("OK", 1);
}
