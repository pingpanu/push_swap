/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:23:19 by pingpanu          #+#    #+#             */
/*   Updated: 2022/07/25 14:36:39 by pingpanu         ###   ########.fr       */
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
