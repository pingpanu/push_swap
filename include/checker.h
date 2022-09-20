/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:18:04 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/21 00:15:51 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

/*this function is to exit when argv can't parsed*/
void	error_exit(t_stack **a, t_stack **b);
/*these functions are in utils_check.c*/
int		checknumeric(char *str);
int		checkdup(t_stack *lst);
int		check_ascend(t_stack **lst);
/*these functions are in parse_argv.c*/
int		argv_split(char **arr, t_stack **a);
int		argv_nor(int size, char **arr, t_stack **a);
/*these functions are for check_sort*/
void	checker_sort(t_stack **a, t_stack **b);
/*these functions are operations*/
void    check_push_a(t_stack **a, t_stack **b);
void    check_push_b(t_stack **a, t_stack **b);
void    check_swap_a(t_stack **a);
void    check_swap_a(t_stack **b);
void    check_swap_ss(t_stack **a, t_stack **b);
void    check_rotate_a(t_stack **a);
void    check_rotate_b(t_stack **b);
void    check_rotate_r(t_stack **a, t_stack **b);
void    check_rrotate_a(t_stack **a);
void    check_rrotate_b(t_stack **b);
void    check_rrotate_r(t_stack **a, t_stack **b);
#endif
