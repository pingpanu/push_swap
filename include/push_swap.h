/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:23:19 by pingpanu          #+#    #+#             */
/*   Updated: 2022/07/25 11:51:13 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

/*include headers*/
# include <stdlib.h>
# include "libft.h"

/*this struct is an elements in column*/
typedef struct	s_node
{
	int		content;
	struct	s_node	*link;
}	t_node;

/*this struct is for analyzed in quicksort*/
typedef struct s_minmax
{
	int		min;
	int		max;
}	t_minmax;


/*this struct is for column*/
typedef struct s_stack
{
	struct s_node	*a;
	struct s_node	*b;
}	t_stack;

int		push_swap(int argc, char **argv);
/*these function are in utils_check.c*/
int		checknumeric(int argc, char **argv);
int		checkvalidint(int argc, char **argv, t_stack *stacks);
#endif
