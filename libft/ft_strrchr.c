/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 18:48:42 by aabdulla          #+#    #+#             */
/*   Updated: 2018/04/12 14:34:03 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;
	int			i;

	p = s;
	i = (int)ft_strlen(s) + 1;
	while (i--)
		if (p[i] == (char)c)
			return ((char *)&p[i]);
	return (NULL);
}
