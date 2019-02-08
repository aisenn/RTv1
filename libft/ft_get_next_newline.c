/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_newline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <aabdulla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:21:43 by aabdulla          #+#    #+#             */
/*   Updated: 2019/02/08 15:21:55 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_get_next_newline(int fd, char **line)
{
	char	*old;
	int		ret;

	if ((ret = get_next_line(fd, line)) > 0)
	{
		old = *line;
		*line = ft_strjoin(*line, "\n");
		ft_strdel(&old);
	}
	else
		return (ret);
	return (ret);
}
