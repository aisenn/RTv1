/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:52:16 by aabdulla          #+#    #+#             */
/*   Updated: 2018/05/29 12:52:42 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*ft_getlst(t_list **head, int fd)
{
	t_list			*cur;

	cur = *head;
	while (cur)
	{
		if ((int)cur->content_size == fd)
			return (cur);
		cur = cur->next;
	}
	cur = ft_lstnew("\0", fd);
	ft_lstadd(head, cur);
	cur = *head;
	return (cur);
}

static int			read_fd_or_write(int fd, void **buff, int *ret, char **line)
{
	char			*tmp;
	void			*old_buff;

	if (!(tmp = ft_strnew(BUFF_SIZE)))
		return (-1);
	if ((*ret = read(fd, tmp, BUFF_SIZE)) < 0)
		return (-1);
	tmp[*ret] = '\0';
	old_buff = *buff;
	if (!(*buff = ft_strjoin(*buff, tmp)))
		return (-1);
	ft_memdel(&old_buff);
	ft_strdel(&tmp);
	if (*ret == 0 && ft_strlen(*buff))
	{
		if (!(*line = ft_strdup(*buff)))
			return (-1);
		ft_bzero(*buff, ft_strlen(*buff));
		return (1);
	}
	return (0);
}

int					get_next_line(int const fd, char **line)
{
	static t_list	*head;
	t_list			*cur;
	char			*nl;
	int				ret;
	int				r;

	if (!line || fd < 0 || (read(fd, 0, 0) < 0))
		return (-1);
	cur = ft_getlst(&head, fd);
	ret = 1;
	while (ret > 0)
	{
		if ((nl = ft_strchr(cur->content, '\n')) != NULL)
		{
			*nl = '\0';
			if (!(*line = ft_strdup(cur->content)))
				return (-1);
			ft_memmove(cur->content, nl + 1, ft_strlen(nl + 1) + 1);
			return (1);
		}
		if ((r = read_fd_or_write(fd, &cur->content, &ret, &(*line))) != 0)
			return (r);
	}
	return (ret);
}
