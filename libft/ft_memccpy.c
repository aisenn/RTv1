/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 19:57:47 by aabdulla          #+#    #+#             */
/*   Updated: 2018/04/03 14:26:40 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *d;
	unsigned char *s;
	unsigned char ch;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	ch = c;
	if (n)
		while (n)
		{
			if ((*d++ = *s++) == ch)
				return (d);
			n--;
		}
	return (0);
}
