/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:09:46 by pingpanu          #+#    #+#             */
/*   Updated: 2022/09/09 15:10:17 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int  ft_abs(int nbr)
{
    if (nbr < 0)
        return (nbr * -1);
    return (nbr);
}