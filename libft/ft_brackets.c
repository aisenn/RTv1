/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brackets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <aabdulla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:53:04 by aabdulla          #+#    #+#             */
/*   Updated: 2019/02/07 16:17:11 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	closing_brackets(char *str, char c, int i, int b)
{
	while (b && *(++str) && (i++))
	{
		if (*str == c || *str == c + c % 2 + 1)
		{
			if (*str == c)
				b++;
			else
				b--;
		}
	}
	return (i);
}

static int	check_brackets(char *str, char c)
{
	if (*str == c)
		return (1);
	else if (!*str || *str == ')' || *str == '}' || *str == ']')
		return (0);
	else if (*str == '(' || *str == '{' || *str == '[')
	{
		return (check_brackets(str + 1, (char)(*str + *str % 2 + 1)) *
				check_brackets(str + closing_brackets(str, *str, 1, 1), c));
	}
	else
		return (check_brackets(str + 1, c));
}

int			ft_brackets(char *str)
{
	return (check_brackets(str, 0));
}
