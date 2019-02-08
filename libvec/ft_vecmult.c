/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecmult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <aabdulla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:30:05 by aabdulla          #+#    #+#             */
/*   Updated: 2019/02/08 15:30:06 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec		ft_vecmult(t_vec v, double scalar)
{
	t_vec	tmp;

	tmp.x = scalar * v.x;
	tmp.y = scalar * v.y;
	tmp.z = scalar * v.z;
	return (tmp);
}
