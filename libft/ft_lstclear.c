/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:47:31 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/06 14:37:13 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_stack **lst)
{
	t_stack	*prev;

	prev = *lst;
	while (*lst)
	{
		*lst = (*lst)->next;
		free(prev);
		prev = *lst ;
	}
	*lst = 0;
}
