/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:17:22 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/20 10:17:50 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
# define OPERATION_H

# include <stdlib.h>
# include "libft.h"
/*they are in swap.c*/
int	swap_a(t_stack **a);
int	swap_b(t_stack **b);
int	swap_ab(t_stack **a, t_stack **b);
/*they are in push.c*/
int	push_a(t_stack **a, t_stack **b);
int	push_b(t_stack **a, t_stack **b);
/*they are in rotate.c*/
int	rotate_a(t_stack **a);
int	rotate_b(t_stack **b);
int	rotate_ab(t_stack **a, t_stack **b);
/*they are in r_rotate.c*/
int	r_rotate_a(t_stack **a);
int	r_rotate_b(t_stack **b);
int	r_rotate_ab(t_stack **a, t_stack **b);
#endif
