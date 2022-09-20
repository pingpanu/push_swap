/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:02:40 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/21 00:16:21 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	check_sort(char *cmd, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(cmd, "pa\n", 3))
		check_push_a(a, b);
	else if (!ft_strncmp(cmd, "pb\n", 3))
		check_push_b(a, b);
	else if (!ft_strncmp(cmd, "sa\n", 3))
		check_swap_a(a);
	else if (!ft_strncmp(cmd, "sb\n", 3))
		check_swap_b(b);
	else if (!ft_strncmp(cmd, "ss\n", 3))
		check_swap_ss(a, b);
	else if (!ft_strncmp(cmd, "ra\n", 3))
		check_rotate_a(a);
	else if (!ft_strncmp(cmd, "rb\n", 3))
		check_rotate_b(b);
	else if (!ft_strncmp(cmd, "rr\n", 3))
		check_rotate_r(a, b);
	else if (!ft_strncmp(cmd, "rra\n", 4))
		check_rrotate_a(a);
	else if (!ft_strncmp(cmd, "rrb\n", 4))
		check_rrotate_b(b);
	else if (!ft_strncmp(cmd, "rrr\n", 4))
		check_rrotate_r(a, b);
	else 
		error_exit(a, b);
}

void	checker_sort(t_stack **a, t_stack **b)
{
	char	*cmd;

	while (1)
	{
		cmd = get_next_line(0);
		if (cmd == NULL)
			break ;
		check_cmd(cmd, a, b);
		free(cmd);
	}
	if (check_ascend(a) && ft_lstsize(*b) == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}
