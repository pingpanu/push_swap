/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argvs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:29:41 by pingpanu          #+#    #+#             */
/*   Updated: 2022/07/11 15:14:52 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**get_nbr(int argc, char **argv)
{
	char	**nbr;
	int	i;

	nbr = (char**)ft_calloc(1, (argc - 1));
	if (!nbr)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		nbr[i] = argv[i + 1];
		i++;
	}
	return (nbr);
}	

static int	check_digit(char **nbr)
{
	int	i;
	int	j;

	i = 0;
	while (nbr[i])
	{
		j = 0;
		while (nbr[i][j])
		{
			if (nbr[i][j] == '-')
				j++;
			if (ft_isdigit(nbr[i][j]))
				return (0);
			j++;
		}
		i++;
	}	
	return (1);
}

char	**check_argvs(int argc, char **argv, int *size)
{
	char	**nbr;
	int	j;

	if (argc == 2)
		nbr = ft_split(argv[1], ' ');
	else
		nbr = get_nbr(argc, argv);
	if (!check_digit(nbr))
		return (NULL);
	while (nbr[*size + 1] != NULL)
	{
		j = *size + 1;
		if (ft_strcmp(nbr[*size], nbr[j]))
			return (NULL);
		(*size)++;
	}
	return (nbr);
}
