/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <aabdulla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:22:24 by aabdulla          #+#    #+#             */
/*   Updated: 2019/02/07 15:23:02 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_count_words(char *str)
{
	int		words;
	char	*ptr;

	if (str == NULL)
		return (0);
	words = 0;
	ptr = str;
	while (*ptr != '\0')
	{
		if (ft_isprint(*ptr) && !ft_isspace(*ptr))
		{
			words++;
			while (ft_isprint(*ptr) && !ft_isspace(*ptr))
				ptr++;
		}
		else
			ptr++;
	}
	return (words);
}
