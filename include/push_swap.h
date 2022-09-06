/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:23:19 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/06 21:51:08 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

/*this struct is for analyzed stacks*/
typedef struct s_param
{
	int		stack_size;
	int		min[2];
	int		max[2];
}	t_param;

void	error_exit(t_stack **a, t_stack **b);
/*these functions are in utils_check.c*/
int		checknumeric(char *str);
int		checkdup(t_stack *lst);
int		check_ascend(t_stack **lst);
int		check_chunk(t_stack **lst, int chunk_size);
/*these functions are in parse_argv.c*/
int		argv_split(char **arr, t_stack **a);
int		argv_nor(int size, char **arr, t_stack **a);
/*these functions are for sorting*/
void	sorting_ops(t_stack **a, t_stack **b);
t_param	get_stack_param(t_stack **lst);
void	tri_sort(t_stack **a, t_param a_par);
void	insertion_sort(t_stack **a, t_stack **b);
void	quick_sort(t_stack **a, t_stack **b, int chunk_a);
#endif