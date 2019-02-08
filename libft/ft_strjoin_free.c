/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <aabdulla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:03:45 by aabdulla          #+#    #+#             */
/*   Updated: 2019/02/07 15:04:47 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin_free(char *left, char *right, char del)
{
	char	*res;

	if ((res = ft_strjoin(left, right)) == 0)
		return (NULL);
	if (del == 'L')
		ft_strdel(&left);
	else if (del == 'R')
		ft_strdel(&right);
	else if (del == 'B')
	{
		ft_strdel(&left);
		ft_strdel(&right);
	}
	return (res);
}
