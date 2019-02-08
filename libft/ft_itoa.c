/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 17:23:57 by aabdulla          #+#    #+#             */
/*   Updated: 2018/04/06 19:21:23 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int len;

	len = 0;
	if (n >= 0)
	{
		if (n == 0)
			return (1);
		while (n != 0)
		{
			n /= 10;
			len++;
		}
	}
	else
	{
		while (n != 0)
		{
			n /= 10;
			len++;
		}
		len++;
	}
	return (len);
}

static void	ft_convert(char **p, int n)
{
	if (n == 0)
		*--*p = '0';
	if (n >= 0)
	{
		while (n != 0)
		{
			*--*p = '0' + (n % 10);
			n = n / 10;
		}
	}
	else
	{
		while (n != 0)
		{
			*--*p = '0' - (n % 10);
			n = n / 10;
		}
		*--*p = '-';
	}
}

char		*ft_itoa(int n)
{
	char	*p;
	int		len;

	len = ft_len(n);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == 0)
		return (NULL);
	p[len] = '\0';
	p = p + len;
	ft_convert(&p, n);
	return (p);
}
