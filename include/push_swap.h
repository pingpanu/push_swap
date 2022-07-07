/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:23:19 by pingpanu          #+#    #+#             */
/*   Updated: 2022/07/07 22:06:33 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

/*include headers*/
# include <stdlib.h>
# include "../libft/libft.h"

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

int	main(int argc, char **argv);
char	**check_argvs(int argc, char **argv, int *size);

#endif
