/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 20:56:34 by aabdulla          #+#    #+#             */
/*   Updated: 2018/04/10 20:56:38 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(const int num)
{
	int		n;
	size_t	len;

	n = (int)num;
	len = 0;
	if (n >= 0)
	{
		if (n == 0)
			return (1);
		while (n != 0)
		{
			n /= 10;
			len++;
		}
	}
	else
	{
		while (n != 0)
		{
			n /= 10;
			len++;
		}
		len++;
	}
	return (len);
}
