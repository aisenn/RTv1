/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbetween_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <aabdulla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:17:38 by aabdulla          #+#    #+#             */
/*   Updated: 2019/02/07 15:20:37 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strbetween_len(char *haystack, char *left, char *right,
	ssize_t *len)
{
	char	*l;
	char	*r;

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
		if (len != NULL)
			*len = r - l;
		return (l);
	}
	return (NULL);
}
