/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:23:19 by pingpanu          #+#    #+#             */
/*   Updated: 2022/08/02 16:15:13 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

/*include headers*/
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

/*this struct is for analyzed in sort*/
typedef struct s_stack_param
{
	int		stack_size;
	int		min[2];
	int		max[2];
}	t_stack_param;

int			main(int argc, char **argv);
void	error_exit(t_stack **a, t_stack **b);
//void	sorting_ops(t_stack **a, t_stack **b);
/*these function are in utils_check.c*/
int			checknumeric(char *str);
int			checkdup(t_stack *lst);
int			check_ascend(t_stack **lst);
int			check_descent(t_stack **lst);
/*these function are in parse_argv.c*/
int			argv_split(char **arr, t_stack **a);
int			argv_nor(int size, char **arr, t_stack **a);
/*these function is for sorting_ops*/
t_stack_param	get_stack_param(t_stack **lst);
#endif
