/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <aabdulla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:20:42 by aabdulla          #+#    #+#             */
/*   Updated: 2019/02/08 15:21:19 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_get_file_content(int fd, int *num_of_lines)
{
	char	*buff;
	char	*line;
	char	*old;

	if (num_of_lines != NULL)
		*num_of_lines = 0;
	if (fd < 0 || (read(fd, 0, 0) < 0))
		return (NULL);
	buff = ft_strnew(1);
	while ((ft_get_next_newline(fd, &line)) > 0)
	{
		old = buff;
		buff = ft_strjoin(buff, line);
		ft_strdel(&line);
		ft_strdel(&old);
		if (num_of_lines != NULL)
			(*num_of_lines)++;
	}
	return (buff);
}
