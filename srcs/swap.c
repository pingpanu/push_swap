/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 22:50:34 by user              #+#    #+#             */
/*   Updated: 2022/08/02 14:32:07 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void     top_swap(t_stack **lst)
{
    t_stack     *node1;
    t_stack     *node2;

    if(!(*lst)->next)
        return ;
    node1 = *lst;
    node2 = (*lst)->next;
    *lst = node2;
    node1->next = node2->next;
    (*lst)->next = node1;
}

void    swap_a(t_stack **a)
{
    top_swap(a);
    ft_putendl_fd("sa", 1);
}

void    swap_b(t_stack **b)
{
    top_swap(b);
    ft_putendl_fd("sb", 1);
}

void    swap_ab(t_stack **a, t_stack **b)
{
    top_swap(a);
    top_swap(b);
    ft_putendl_fd("ss", 1);
}

/*for test only

static void		free_stack(t_stack **a, t_stack **b)
{
	ft_lstclear(a);
	ft_lstclear(b);
	a = NULL;
	b = NULL;
}

static void	print_data(t_stack *head)
{
	if (head == NULL)
		printf("The stack is empty");
	while (head != NULL)
	{
		printf("%d->", head->data);
		head = head->next;
	}
	printf("\n");
}

int main()
{
    t_stack *a;
    t_stack *new;

    a = NULL;
    for(int i=0; i < 5; i++)
    {
        new = ft_lstnew(i);
        ft_lstadd_back(&a, new);
    }
    ft_putendl_fd("before swap", 1);
    print_data(a);
    top_swap(&a);
    ft_putendl_fd("after swap", 1);
    print_data(a);
    ft_lstclear(&a);
    a = NULL;
    return (0);
}*/