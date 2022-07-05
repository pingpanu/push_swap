/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:27:42 by pingpanu          #+#    #+#             */
/*   Updated: 2022/07/05 14:12:58 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "messages.h"

/*main will do the following things
 * parse argv to array of ints
 * check the array of ints
 * if array of ints is good, start push_swaps
 */
int	main(int argc, char **argv)
{
	int	a_col[500]; //column a

	if (argc >= 2)
	{
		a_col = parse_arr(argc, argv);
		if (check_arr(a_col));
			pushswap(a_col);
		else
			ft_putendl(ERROR);

	}
	else
		ft_putendl(ERROR);
	return (0);
}
