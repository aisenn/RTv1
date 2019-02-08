/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_veclength.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <aabdulla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:29:51 by aabdulla          #+#    #+#             */
/*   Updated: 2019/02/08 15:29:51 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

double	ft_veclength(t_vec vec)
{
	return (sqrt(ft_vecdot(vec, vec)));
}
