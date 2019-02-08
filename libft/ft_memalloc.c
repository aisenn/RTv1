/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:04:36 by aabdulla          #+#    #+#             */
/*   Updated: 2018/04/02 14:03:31 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *arr;

	arr = NULL;
	if (size > 0)
		if ((arr = (char *)malloc(size)) != NULL)
		{
			while (size != 0)
				arr[--size] = '\0';
			return ((void *)arr);
		}
	return ((void *)arr);
}
