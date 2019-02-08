/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbetween_sub.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <aabdulla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:07:00 by aabdulla          #+#    #+#             */
/*   Updated: 2019/02/07 15:17:02 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strbetween_sub(char *haystack, char *left, char *right)
{
	char			*res;
	char			*l;
	char			*r;
	unsigned long	start;

	res = NULL;
	r = NULL;
	if (haystack == NULL || left == NULL || right == NULL)
		return (NULL);
	if ((l = ft_strstr(haystack, left)) != NULL)
	{
		l = l + ft_strlen(left);
		r = ft_strstr(l, right);
	}
	if (l != NULL && r != NULL && l < r)
	{
		start = l - haystack;
		res = ft_strsub(haystack, (unsigned int)start, r - l);
	}
	return (res);
}
