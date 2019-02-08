/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 20:30:51 by aabdulla          #+#    #+#             */
/*   Updated: 2018/04/10 17:14:06 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*hend;
	const char	*h;
	const char	*n;
	size_t		a;

	if (!*needle)
		return ((char *)haystack);
	hend = haystack + len;
	while (*haystack && haystack <= hend)
	{
		a = ft_strlen(needle);
		if (a > len)
			return (NULL);
		h = haystack;
		n = needle;
		while (*h && *n && h < hend)
			if (*h++ != *n)
				break ;
			else
				n++;
		if (*n == 0)
			return ((char*)haystack);
		haystack++;
	}
	return (0);
}
