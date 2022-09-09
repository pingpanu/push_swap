/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:06:38 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/09 15:10:15 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int  get_mid(t_stack *lst, t_param par)
{
    int     mid;
    int     cur;

    mid = (par.max[0] + par.min[0]) / 2;
    cur = lst->data;
    while (lst != NULL)
    {
        if (ft_abs(mid - lst->data) < (mid - cur))
            cur = lst->data;
        lst = lst->next; 
    }
    return (cur);
}