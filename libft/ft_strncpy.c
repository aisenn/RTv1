/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:22:42 by aabdulla          #+#    #+#             */
/*   Updated: 2018/03/30 20:30:23 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *d;

	d = dst;
	while (len > 0 && *src != '\0')
	{
		*d++ = *src++;
		--len;
	}
	while (len > 0)
	{
		*d++ = '\0';
		--len;
	}
	return (dst);
}
