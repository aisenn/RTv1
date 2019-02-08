/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:52:43 by aabdulla          #+#    #+#             */
/*   Updated: 2018/03/23 16:04:36 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (res != NULL)
	{
		res[i] = '\0';
		i = 0;
		while (s1[i] != '\0')
		{
			res[i] = s1[i];
			i++;
		}
		return (res);
	}
	return (0);
}
