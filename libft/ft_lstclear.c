/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:47:31 by pingpanu          #+#    #+#             */
/*   Updated: 2022/07/25 14:53:54 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_node **lst, void (*del)(void*))
{
	t_node	*prev;

	if (lst && del)
	{
		prev = *lst;
		while (*lst)
		{
			*lst = (*lst)->next;
			del(prev->data);
			free(prev);
			prev = *lst;
		}
		*lst = 0;
	}
}
