/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 19:47:05 by aabdulla          #+#    #+#             */
/*   Updated: 2018/04/03 21:18:43 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		n;

	if (!s)
		return (NULL);
	n = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (s[n] != '\0')
		n++;
	while ((s[n - 1] == ' ' || s[n - 1] == '\n' || s[n - 1] == '\t') && *s)
		n--;
	str = (char *)malloc(sizeof(char) * (n + 1));
	if (str == 0)
		return (NULL);
	str[n--] = '\0';
	while (n + 1 > 0)
	{
		str[n] = s[n];
		n--;
	}
	return (str);
}
