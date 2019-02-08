/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 17:19:32 by aabdulla          #+#    #+#             */
/*   Updated: 2018/08/21 17:19:35 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int num, int pow)
{
	if (num == 0 || pow < 0)
		return (0);
	else if (pow == 0)
		return (1);
	else if (pow == 1)
		return (num);
	return (num * ft_pow(num, pow - 1));
}
