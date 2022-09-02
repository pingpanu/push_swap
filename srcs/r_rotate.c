/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:09:54 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/02 14:51:17 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	r_rotate_stack(t_stack **lst)
{
	t_stack	*temp;

	if (!(*lst)->next)
		return ;
	temp = *lst;
	*lst = temp->next;
	temp->next = NULL;
	ft_lstadd_back(lst, temp);
}

void	r_rotate_a(t_stack **a)
{
	r_rotate_stack(a);
	ft_putendl_fd("rra", 1);
}

void	r_rotate_b(t_stack **b)
{
	r_rotate_stack(b);
	ft_putendl_fd("rrb", 1);
}

void	r_rotate_ab(t_stack **a, t_stack **b)
{
	r_rotate_stack(a);
	r_rotate_stack(b);
	ft_putendl_fd("rrr", 1);
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

    a = NULL;
    int     i = 0;
    while (i < 5)
    {
        new = ft_lstnew(arr[i]);
        ft_lstadd_back(&a, new);
        i++;
    }
    print_lst(a);
    r_rotate_a(&a);
    print_lst(a);
    return (0);
}