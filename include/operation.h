/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 22:55:48 by user              #+#    #+#             */
/*   Updated: 2022/08/05 17:09:12 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
# define OPERATION_H

# include <stdlib.h>
# include "libft.h"
/*they are in swap.c*/
void    swap_a(t_stack **a);
void    swap_b(t_stack **b);
void    swap_ab(t_stack **a, t_stack **b);
/*they are in push.c*/
void    push_a(t_stack **a, t_stack **b);
void    push_b(t_stack **a, t_stack **b);
/*they are in rotate.c*/
void    rotate_a(t_stack **a);
void    rotate_b(t_stack **b);
void    rotate_ab(t_stack **a, t_stack **b);
/*they are in r_rotate.c*/
void    r_rotate_a(t_stack **a);
void    r_rotate_b(t_stack **b);
void    r_rotate_ab(t_stack **a, t_stack **b);
#endif