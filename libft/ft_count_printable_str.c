/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_printable_str.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <aabdulla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:21:29 by aabdulla          #+#    #+#             */
/*   Updated: 2019/02/07 15:22:05 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_count_printable_str(char *str)
{
	int		words;
	char	*ptr;

	if (str == NULL)
		return (0);
	words = 0;
	ptr = str;
	while (*ptr != '\0')
	{
		if (ft_isprint(*ptr))
		{
			words++;
			while (ft_isprint(*ptr))
				ptr++;
		}
		else
			ptr++;
	}
	return (words);
}
