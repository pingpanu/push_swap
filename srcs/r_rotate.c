/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 22:27:33 by user              #+#    #+#             */
/*   Updated: 2022/07/30 23:02:46 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	    print_data(t_stack *head);

static void     r_rotate_stack(t_stack **lst)
{
    t_stack     *temp;
    t_stack     *cursor;

    if(!(*lst)->next)
        return ;
    cursor = *lst;
    while (cursor->next->next!= NULL)
        cursor = cursor->next;
    temp = cursor->next;
    cursor->next = NULL;
    ft_lstadd_front(lst, temp);
}

void    r_rotate_a(t_stack **a)
{
    r_rotate_stack(a);
    ft_putendl_fd("ra", 1);
}

void    r_rotate_b(t_stack **b)
{
    r_rotate_stack(b);
    ft_putendl_fd("rb", 1);
}

void    r_rotate_ab(t_stack **a, t_stack **b)
{
    r_rotate_stack(a);
    r_rotate_stack(b);
    ft_putendl_fd("rr", 1);
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
    ft_putendl_fd("before rotate_a", 1);
    print_data(a);
    r_rotate_a(&a);
    ft_putendl_fd("after rotate_a", 1);
    print_data(a);
    ft_lstclear(&a);
    a = NULL;
    return (0);
}*/