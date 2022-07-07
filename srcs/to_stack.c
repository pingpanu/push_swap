/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argvs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:57:47 by pingpanu          #+#    #+#             */
/*   Updated: 2022/07/07 21:27:51 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*to_stack(int argc, char **nbr)
{
	t_stack	*ret_stack;
	int		size;

	if (!check_argvs(argc, nbr))
		return (NULL);
	size = check_size(argc, nbr);
	ret_stack = ft_calloc(1, sizeof(t_stack));
	if (!ret_stack)
		return (NULL);
	return (ret_stack);
}
