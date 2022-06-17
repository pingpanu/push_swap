/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:27:42 by pingpanu          #+#    #+#             */
/*   Updated: 2022/06/17 17:01:43 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

int	argv_dup(int argc, char **argv);

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	if (!argv_dup(argc, argv))
	{
		printf("error\n");
		return (1);
	}
	for (int i = 1; i < argc; i++)
		printf("%s\n",argv[i]);
	return (0);
}

int	argv_dup(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (strcmp(argv[i], argv[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
