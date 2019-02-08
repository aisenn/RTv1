/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 17:22:43 by aabdulla          #+#    #+#             */
/*   Updated: 2018/08/23 16:14:02 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi_base(char *str, int base)
{
	int		num;
	size_t	len;
	size_t	i;

	num = 0;
	len = ft_strlen(str);
	i = 0;
	while (len--)
	{
		if (ft_isalpha(str[len]) && (ft_toupper(str[len]) > 'F'))
			return (0);
		if (ft_isdigit(str[len]))
			num = num + (str[len] - '0') * ft_pow(base, i);
		else
			num = num + (ft_toupper(str[len]) - 'A' + 10) * ft_pow(base, i);
		i++;
	}
	return (num);
}
