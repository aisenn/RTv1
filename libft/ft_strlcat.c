/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 15:55:54 by aabdulla          #+#    #+#             */
/*   Updated: 2018/03/27 16:14:17 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	char	*p;

	i = 0;
	j = 0;
	p = dst;
	while (*p)
	{
		i++;
		p++;
	}
	while (src[j] != '\0')
		j++;
	if (i >= dstsize)
		return (j + dstsize);
	dstsize -= i;
	while (*src && dstsize != 1)
	{
		*p++ = *src++;
		dstsize--;
	}
	*p = '\0';
	return (i + j);
}
