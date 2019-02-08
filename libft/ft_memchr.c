/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:42:46 by aabdulla          #+#    #+#             */
/*   Updated: 2018/03/23 14:22:49 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *arr;

	arr = (unsigned char *)s;
	while (n)
	{
		if (*arr != (unsigned char)c)
			arr++;
		else
			return (arr);
		n--;
	}
	return (NULL);
}
