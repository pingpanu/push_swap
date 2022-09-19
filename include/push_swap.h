/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:23:19 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/19 16:19:25 by user             ###   ########.fr       */
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
int		check_descend(t_stack **lst);
//int		check_chunk(t_stack **lst, int chunk_size);
/*these functions are in parse_argv.c*/
int		argv_split(char **arr, t_stack **a);
int		argv_nor(int size, char **arr, t_stack **a);
/*these functions are for sorting*/
void	sorting_ops(t_stack **a, t_stack **b);
void	tri_sort(t_stack **a, t_param a_par);
void	tri_sort_b(t_stack **b, t_param b_par);
void	insertion_sort(t_stack **a, t_stack **b, int b_size);
void	quick_sort(t_stack **a, t_stack **b, int chunk_a);
/*these functions are utility for all algorithm*/
int		get_mid(t_stack *lst, t_param par);
int		push_back(t_stack **a, t_stack **b);
t_param	get_stack_param(t_stack **lst, int limit);
/*these functions are utility for insertion_sort*/
int		get_ascend_stack(t_stack **lst);
int		a_gap(t_stack **a);
void	insert_swap(t_stack **a, t_stack **b);
#endif