/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:47:49 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/19 16:47:13 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operation.h"
/*#include <stdio.h>

static void     print_lst(t_stack *lst)
{
    if (lst == NULL)
        printf("Linked list is empty\n");
    while (lst != NULL)
    {
        printf("%d ->", lst->data);
        lst = lst->next;
    }
    printf("\n");
}*/

/*  consider how actual insertion_sort work, this thing should be called bubble_sort  */
/*  but push_swap limitation make bubble sort as fast as insertion_sort               */

static void	a_max_to_last(t_stack **a, t_param *a_par)
{
	int		a_mid;

	a_mid = (a_par->stack_size / 2) + 1;
	while (a_par->max[1] < a_par->stack_size)
	{
		if (a_par->max[1] < a_mid)
		{
			a_par->max[1] -= rotate_a(a);
			if (a_par->max[1] < 1)
				a_par->max[1] = a_par->stack_size;
		}
		else
			a_par->max[1] += r_rotate_a(a);
	}
}

static int	max_ascend(t_stack **a, t_param a_par)
{
	int		ascend;

	ascend = get_ascend_stack(a);
	if (a_par.max[1] == ascend)
		return (1);
	return (0);
}

static int	check_and_swap(t_stack **a, t_stack **b, t_param *a_par)
{
	if (check_ascend(a))
		return (0);
	insert_swap(a, b);
	if (check_ascend(a))
		return (0);
	a_par->stack_size -= push_b(a, b);
	return (1);
}

void	insertion_sort(t_stack **a, t_stack **b, int b_size)
{
	t_param	a_par;
	int		b_limit;

	a_par = get_stack_param(a, 0);
	if (max_ascend(a, a_par))
		a_max_to_last(a, &a_par);
	if (check_ascend(a))
		return ;
	while (a_par.stack_size > 3)
	{
		if (!check_and_swap(a, b, &a_par))
			break ;
	}
	if (!check_ascend(a) && a_par.stack_size == 3)
		tri_sort(a, get_stack_param(a, 0));
	/*printf("Stack a = %d\n", ft_lstsize(*a));
    print_lst(*a);
    printf("Stack b = %d\n", ft_lstsize(*b));
    print_lst(*b);*/
	b_limit = ft_lstsize(*b) - b_size;
	while (b_limit > 0)
	{
		if (a_gap(a) != 1)
			b_limit += push_b(a, b);
		b_limit -= push_back(a, b);
	}
	/*printf("Stack a = %d\n", ft_lstsize(*a));
    print_lst(*a);
    printf("Stack b = %d\n", ft_lstsize(*b));
    print_lst(*b);*/
}