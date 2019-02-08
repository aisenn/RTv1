/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:22:29 by aabdulla          #+#    #+#             */
/*   Updated: 2018/03/22 18:59:21 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *res;

	res = (unsigned char *)b;
	if (len != 0)
		while (len)
		{
			*res++ = (unsigned char)c;
			len--;
		}
	return (b);
}
