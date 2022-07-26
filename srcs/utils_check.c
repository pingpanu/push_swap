/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:29:41 by pingpanu          #+#    #+#             */
/*   Updated: 2022/07/26 16:46:31 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	checknumeric(char *str)
{
	while(*str)
	{
		if ((*str >= 9 && *str <= 13) || *str == 32)
			str++;
		else if (!ft_isdigit(*str) && *str != '-')
			return (0);
		str++;
	}
	return (1);
}

int		checkvalidint(char *nbr, t_stack *temp)
{
	char	*check;

	printf("%s %d", nbr, temp->data);
	check = ft_itoa(temp->data);
	if (ft_strcmp(check, nbr) != 0)
	{
		free(check);
		return (0);
	}
	free(check);
	return (1);
}

int      checkdup(t_stack *lst)
{
    t_stack *check;

    check = ft_lstlast(lst);
    while (lst != check)
    {
        if (lst->data == check->data)
            return (0);
        lst = lst->next;
    }
	return (1);
}
/*for test only
#include <stdio.h>
int	main(int argc, char **argv)
{
	if (argc != 1)
	{
		if (checknumeric(argc, argv) == 1)
			printf("argvs are numeric");
		else
			printf("argvs aren't numeric");
		return (0);
	}
	return (0);
}*/