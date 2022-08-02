/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:21:55 by pingpanu          #+#    #+#             */
/*   Updated: 2022/08/02 16:04:33 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static unsigned int     ft_fabs(int nbr)
{
    unsigned int    unb;

    if(nbr < 0)
        unb = -nbr;
    else
        unb = nbr;
    return (unb);
}

static int      get_min(t_stack **lst, int *pos)
{
    int     min;

    min = INT_MAX;
    while (*lst != NULL)
    {
        if (min > (*lst)->data)
            min = (*lst)->data;
        pos++;
        *lst = (*lst)->next;
    }
    return (min);
}

static int      get_max(t_stack **lst, int *pos)
{
    int     max;

    max = INT_MIN;
    while (*lst != NULL)
    {
        if (max < (*lst)->data)
            max = (*lst)->data;
        pos++;
        *lst = (*lst)->next;
    }
    return (max);
}

static int      get_med(t_stack **lst, t_stack_param *param)
{
    int     med;
    int     temp;
    int     calc;

    temp = 99999;
    med = (param->min[0] + param->max[0]) / 2;
    while (*lst != NULL)
    {
        calc = ft_fabs((*lst)->data - med);
        if (calc <= temp)
            temp = calc;
        param->med[1]++;
        *lst = (*lst)->next;
    }
    return (med);
}

t_stack_param   get_stack_param(t_stack **lst)
{
    t_stack_param   param;

    param.stack_size = ft_lstsize(*lst);
    param.min[1] = 0;
    param.med[1] = 0;
    param.max[1] = 0;
    param.min[0] = get_min(lst, &param.min[1]);
    param.max[0] = get_max(lst, &param.max[1]);
    param.max[0] = get_med(lst, &param);
    return (param);
}