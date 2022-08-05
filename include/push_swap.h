/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:23:19 by pingpanu          #+#    #+#             */
/*   Updated: 2022/08/05 17:09:11 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

/*include headers*/
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

/*this struct is for analyzed stacks*/
typedef struct s_stack_param
{
	size_t	stack_size;
	int			min[2];
	int			max[2];
}	t_stack_param;

/*this struct is for insertion sort*/
typedef struct s_ins_comp
{
	size_t	b_size;
	int		status;
	/*status value
	* -1 = ((*a) > (*a)->next && (b_size < 2 || (*b) > (*b)->next)) = sa
	* 0 = ((*a) < (*a)->next && (b_size < 2 || (*b) > (*b)->next)) = pb
	* 1 = ((*a) < (*a)->next && ((*b) < (*b)->next)) = 
	* 2 = ((*a) > (*a)->next && ((*b) > (*b)->next)) = 
	*/ 
}	t_ins_comp;

int			main(int argc, char **argv);
void	error_exit(t_stack **a, t_stack **b);
/*these functions are in utils_check.c*/
int			checknumeric(char *str);
int			checkdup(t_stack *lst);
int			check_ascend(t_stack **lst);
int			check_descent(t_stack **lst);
/*these functions are in parse_argv.c*/
int			argv_split(char **arr, t_stack **a);
int			argv_nor(int size, char **arr, t_stack **a);
/*these functions are in sorting_ops*/
void	sorting_ops(t_stack **a, t_stack **b);
t_stack_param	get_stack_param(t_stack **lst);
/*these are algorithms*/
void	insertion_sort(t_stack **a, t_stack **b, t_stack_param a_par);
#endif
