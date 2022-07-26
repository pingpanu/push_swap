/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:23:19 by pingpanu          #+#    #+#             */
/*   Updated: 2022/07/26 16:54:59 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

/*include headers*/
# include <stdlib.h>
# include "libft.h"

/*this struct is for analyzed in quicksort*/
typedef struct s_minmax
{
	int		min;
	int		max;
}	t_minmax;

int			main(int argc, char **argv);
void	error_exit(t_stack *a, t_stack *b);
/*these function are in utils_check.c*/
int			checknumeric(char *str);
//int			checkvalidint(char *nbr, t_stack *temp);
int			checkdup(t_stack *lst);
/*these function are in parse_argv.c*/
int			argv_split(char **arr, t_stack **a);
int			argv_nor(int size, char **arr, t_stack **a);
#endif
