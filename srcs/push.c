/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:59:03 by user              #+#    #+#             */
/*   Updated: 2022/07/30 22:10:12 by user             ###   ########.fr       */
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
    t_stack *b;
    t_stack *new;

    a = NULL;
    b = NULL;
    for(int i=0; i < 5; i++)
    {
        new = ft_lstnew(i);
        ft_lstadd_back(&a, new);
    }
    ft_putendl_fd("before push_b", 1);
    print_data(a);
    print_data(b);
    for (int j=0; j < 5; j++)
        push_b(&a, &b);
    ft_putendl_fd("after push_b", 1);
    print_data(a);
    print_data(b);
    for (int k=0; k < 2; k++)
        push_a(&a, &b);
    ft_putendl_fd("after push_a", 1);
    print_data(a);
    print_data(b);
    ft_lstclear(&a);
    ft_lstclear(&b);
    a = NULL;
    b = NULL;
    return (0);
}*/