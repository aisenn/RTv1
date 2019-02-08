/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 18:08:48 by aabdulla          #+#    #+#             */
/*   Updated: 2018/04/06 16:19:19 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (0);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str)
	{
		str[len] = '\0';
		while (len--)
			str[i++] = s[start++];
		return (str);
	}
	return (NULL);
}
