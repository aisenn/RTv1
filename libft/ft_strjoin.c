/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 18:57:08 by aabdulla          #+#    #+#             */
/*   Updated: 2018/04/06 16:56:23 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	k = 0;
	str = (char *)malloc(sizeof(char) * (i + j + 1));
	if (str == NULL)
		return (0);
	while (*s1)
		str[k++] = *s1++;
	while (*s2)
		str[k++] = *s2++;
	str[i + j] = '\0';
	return (str);
}
