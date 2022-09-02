/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:48:54 by user              #+#    #+#             */
/*   Updated: 2022/09/02 16:05:24 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"

void	tri_sort(t_stack **a, t_param a_par)
{
	if (a_par.max[1] == 2)
	{
		rotate_a(a);
		if (a_par.min[1] == 1)
			swap_a(a);
	}
	else if (a_par.min[1] == 2)
	{
		if (a_par.max[1] == 3)
			swap_a(a);
		else
			r_rotate_a(a);
	}
	else
	{
		r_rotate_a(a);
		swap_a(a);
	}
}

void	sorting_ops(t_stack **a, t_stack **b)
{
	int	a_size;

	a_size = ft_lstsize(*a);
	if (a_size == 1)
		return ;
	else if (a_size == 2)
	{
		if (!check_ascend(a))
			swap_a(a);
	}
	else if (a_size > 3 && a_size <= 50)
		insertion_sort(a, b);
	else
		quick_sort(a, b);
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
