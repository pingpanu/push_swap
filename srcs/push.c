/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:59:03 by user              #+#    #+#             */
/*   Updated: 2022/08/07 11:38:47 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void     push_a(t_stack **a, t_stack **b)
{
    t_stack     *push;
    
    if (!(*b))
        return ;
    push = *b;
    *b = push->next;
    push->next = NULL;
    ft_lstadd_front(a, push);
    ft_putendl_fd("pa", 1);
}

void    push_b(t_stack **a, t_stack **b)
{
    t_stack     *push;

    if (!(*a))
        return ;
    push = *a;
    *a = push->next;
    push->next = NULL;
    ft_lstadd_front(b, push);
    ft_putendl_fd("pb", 1);
}