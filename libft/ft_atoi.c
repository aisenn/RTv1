/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 17:12:35 by aabdulla          #+#    #+#             */
/*   Updated: 2018/04/06 17:13:01 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	num;
	int					m;

	num = 0;
	m = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			m = 1;
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str++ - '0');
		if (num >= 9223372036854775808ull)
			return (m ? 0 : -1);
	}
	return (m ? -num : num);
}
