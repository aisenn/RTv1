/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:14:55 by aabdulla          #+#    #+#             */
/*   Updated: 2018/03/27 16:15:58 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char *p;

	p = s;
	while (*p != '\0')
	{
		if (*p == c)
			return ((char *)p);
		p++;
	}
	if (c == '\0')
		return ((char *)p);
	return (NULL);
}
