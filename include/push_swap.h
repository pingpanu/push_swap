/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:23:19 by pingpanu          #+#    #+#             */
/*   Updated: 2022/08/01 22:51:31 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

/*include headers*/
# include <stdlib.h>
# include "libft.h"

/*this struct is for analyzed in sort*/
typedef struct s_stack_param
{
	int		stack_size;
	int		min;
	int		min_pos;
	int		med;
	int		med_pos;
	int		max;
	int		max_pos
}	t_stack_param;

int			main(int argc, char **argv);
void	error_exit(t_stack **a, t_stack **b);
void	sorting_ops(t_stack **a, t_stack **b);
/*these function are in utils_check.c*/
int			checknumeric(char *str);
int			checkdup(t_stack *lst);
int			check_ascend(t_stack **lst);
int			check_descent(t_stack **lst);
/*these function are in parse_argv.c*/
int			argv_split(char **arr, t_stack **a);
int			argv_nor(int size, char **arr, t_stack **a);
#endif