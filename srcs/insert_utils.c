/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:40:22 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/20 09:41:58 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

int	get_ascend_stack(t_stack **lst)
{
	int		ret;
	t_stack	*cur;

	ret = 1;
	cur = *lst;
	while (cur->next != NULL)
	{
		if (cur->data > cur->next->data)
			break ;
		cur = cur->next;
		ret++;
	}
	return (ret);
}

void	insert_swap(t_stack **a, t_stack **b)
{
	int	need_sa;
	int	need_sb;

	need_sa = 0;
	need_sb = 0;
	if ((*a)->data > (*a)->next->data)
		need_sa = 1;
	if (ft_lstsize(*b) > 1 && (*b)->data < (*b)->next->data)
		need_sb = 1;
	if (need_sa == 1 && need_sb == 0)
		swap_a(a);
	else if (need_sa == 0 && need_sb == 1)
		swap_b(b);
	else if (need_sa == 1 && need_sb == 1)
		swap_ab(a, b);
	else
		return ;
}
