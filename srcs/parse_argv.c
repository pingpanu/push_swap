/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:57:47 by pingpanu          #+#    #+#             */
/*   Updated: 2022/07/25 17:17:37 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int      valid_integer(char *nbr, t_stack **a)
{
    t_stack     *temp;

    temp = ft_lstnew(ft_atoi(nbr));
    if (!temp || !checkvalidint(temp, nbr))
        return (0);
    ft_lstadd_back(a, temp);
    return (1);
}

static int      valid_dup(t_stack *stack)
{
    t_stack *check;

    check = ft_lstlast(stack);
    while (stack != check)
    {
        if (stack->data == check->data)
            return (0);
        stack = stack->next;
        return (1);
    }
}

static void     free_array(char **arr)
{
    while(*arr != 0)
    {
        free(*arr);
        arr++;
    }
    free(arr);
}

int			argv_split(char **arr, t_stack **a)
{
    int     i;

    arr = ft_split(arr[0], ' ');
    i = 0;
    while (arr[i])
    {
        if (!valid_integer(arr[i++], a))
        {
            free_array(arr);
            return (0);
        }
        if (!valid_dup(*a))
        {
            free_array(arr);
            return (0);
        }
    }
    free_array(arr);
    return (1);
}

int     argv_nor(int size, char **arr, t_stack **a)
{
    int     i;

    i = 0;
    while (i < size)
    {
        if (ft_strlen(arr[i]) == 0)
            return (0);
        if (!valid_integer(arr[i++], a))
            return (0);
        if (!valid_dup(*a))
            return (0);
    }
    return (1);
}