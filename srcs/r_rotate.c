/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 22:27:33 by user              #+#    #+#             */
/*   Updated: 2022/08/07 11:38:11 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void     r_rotate_stack(t_stack **lst)
{
    t_stack     *temp;
    t_stack     *cursor;

    if(!(*lst)->next)
        return ;
    cursor = *lst;
    while (cursor->next->next!= NULL)
        cursor = cursor->next;
    temp = cursor->next;
    cursor->next = NULL;
    ft_lstadd_front(lst, temp);
}

void    r_rotate_a(t_stack **a)
{
    r_rotate_stack(a);
    ft_putendl_fd("ra", 1);
}

void    r_rotate_b(t_stack **b)
{
    r_rotate_stack(b);
    ft_putendl_fd("rb", 1);
}

void    r_rotate_ab(t_stack **a, t_stack **b)
{
    r_rotate_stack(a);
    r_rotate_stack(b);
    ft_putendl_fd("rr", 1);
}