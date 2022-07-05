/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:23:19 by pingpanu          #+#    #+#             */
/*   Updated: 2022/07/05 14:50:24 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

/*include headers*/
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include "libft.h"

/*column struct including
 * a_col: array of int a
 * b_col: aray of int b
 * sub: array of sub
 * size_a: size of a_col
 * size_b: size of b_col
 * size_sub: size of sub
 */
typedef struct	s_stack
{
	int	*a_col;
	int	*b_col;
	int	*sub;
	size_t	size_a;
	size_t	size_b;
	size_t	size_sub;
}	t_stack;

#endif
