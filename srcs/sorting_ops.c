/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:48:54 by user              #+#    #+#             */
/*   Updated: 2022/08/08 17:44:27 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

static int      get_min(t_stack *lst)
{
    int     min;

    min = INT_MAX;
    while (lst != NULL)
    {
        if (min > lst->data)
            min = lst->data;
        lst = lst->next;
    }
    return (min);
}

static int      get_max(t_stack *lst)
{
    int     max;

    max = INT_MIN;
    while (lst != NULL)
    {
        if (max < lst->data)
            max = lst->data;
        lst = lst->next;
    }
    return (max);
}

static int      get_pos(t_stack *lst, int nbr)
{
    int     pos;

    pos = 1;
    while (lst != NULL)
    {
        if (lst->data == nbr)
            break ;
        pos++;
        lst = lst->next;
    }
    return (pos);
}

t_stack_param   get_stack_param(t_stack **lst)
{
    t_stack_param   param;

    param.stack_size = (size_t)ft_lstsize(*lst);
    param.min[0] = get_min(*lst);
    param.max[0] = get_max(*lst);
    param.min[1] = get_pos(*lst, param.min[0]);
    param.max[1] = get_pos(*lst, param.max[0]);
    return (param);
}

void    sorting_ops(t_stack **a, t_stack **b)
{
    t_stack_param   a_par;

    a_par = get_stack_param(a);
    if (a_par.stack_size == 1)
        return ;
    else if (a_par.stack_size == 2)
    {
        if (!check_ascend(a))
            swap_a(a);
    }
    else
        insertion_sort(a, b, a_par);
    /*else if (a_par.stack_size > 50 && a_par.stack_size < 101)
        quick_sort(a, b, a_par);
    else
        super_sort(a, b, a_par);*/
}

#include <stdio.h>

static void     print_lst(t_stack *lst)
{
    if (lst == NULL)
        printf("Stack is empty");
    while (lst != NULL)
    {
        printf("%d-> ",lst->data);
        lst = lst->next;
    }
    printf("\n");
}

int     main()
{
    int     arr[5] = {3, 1, 5, 2, 4};
    t_stack     *new;
    t_stack     *a;
    t_stack     *b;

    a = NULL;
    b = NULL;
    int     i = 0;
    while (i < 5)
    {
        new = ft_lstnew(arr[i]);
        ft_lstadd_back(&a, new);
        i++;
    }
    print_lst(a);
    sorting_ops(&a, &b);
    print_lst(a);
    print_lst(b);
    return (0);
}