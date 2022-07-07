/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argvs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:57:47 by pingpanu          #+#    #+#             */
/*   Updated: 2022/07/07 20:09:18 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"

int	check_dups(char	**nbr, int mode)
{
	int	i;
	int	j;

	i = 1;
	if (mode == 0)
		i = 0;
	while (nbr[i])i
	{
		j = i + 1;
		while (*nbr[j])
		{
			if (

int	check_argvs(int argc, char **argv, t_stack *stack)
{
	char	**nbr;
	int	mode;

	if (argc == 2)
	{
		nbr = ft_split(argv[1], ' ');
		mode = 0;
	}
	else
	{
		nbr = argv;
		mode = 1;
	}
	if (!check_dups(nbr, mode))
		return (0);
	else if (!check_digits(nbr, mode))
		return (0);
	else
		return (1);
}
