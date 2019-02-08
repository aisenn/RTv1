/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <aabdulla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 22:03:03 by aabdulla          #+#    #+#             */
/*   Updated: 2019/02/07 22:03:04 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_obj	*add_link(t_obj *tmp, t_obj *link)
{
	t_obj		*head;

	head = tmp;
	if (tmp == NULL)
		return (link);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = link;
	return (head);
}

static int		additional_settings(t_obj *link, char *ptr)
{
	char		*rot;
	char		*size;
	char		*intensity;

	if (link->type == POINT || link->type == AMBIENT)
	{
		if ((intensity = ft_strbetween_len(ptr, "intensity(", ")", 0)) == NULL)
			return (-1);
		link->intensity = ft_atoi(intensity);
	}
	if (link->type == CYLINDER || link->type == CONE || link->type == SPHERE)
	{
		if ((size = ft_strbetween_len(ptr, "size(", ")", 0)) == NULL)
			return (-1);
		link->size = ft_atoi(size);
	}
	if (link->type == PLANE || link->type == CONE || link->type == CYLINDER)
	{
		if ((rot = ft_strbetween_sub(ptr, "rot(", ")")) == NULL)
			return (-1);
		if ((get_dimensions_var(&link->rot, &rot)) == -1)
			return (ft_error(&rot, NULL));
		ft_strdel(&rot);
	}
	return (0);
}

static int		set_parameters(t_obj *link, char *ptr)
{
	char		*col;
	char		*pos;

	if ((col = ft_strbetween_sub(ptr, "col(", ")")) == NULL)
		return (-1);
	if ((pos = ft_strbetween_sub(ptr, "pos(", ")")) == NULL)
		return (ft_error(&col, NULL));
	if ((get_dimensions_var(&link->color, &col)) == -1)
		return (ft_error(&pos, NULL));
	if ((get_dimensions_var(&link->pos, &pos)) == -1)
		return (-1);
	return (additional_settings(link, ptr));
}

static int		ft_add_obj(t_mlx *mlx, char *str, int type)
{
	t_obj		*link;
	char		*begin;
	char		*end;

	if (!(link = (t_obj *)malloc(sizeof(t_obj))))
		return (-1);
	link->type = type;
	link->intensity = 0;
	link->size = 0;
	link->rot = (t_vec){0, 0, 0};
	link->next = NULL;
	link->spec = 20;
	link->refl = 0.3;
	if (set_parameters(link, str) == -1)
		return (-1);
	begin = ft_strstr(str, "object");
	end = ft_strchr(begin, '}');
	if (begin && end)
		ft_memset(begin, '-', end - begin);
	if (type == POINT || type == AMBIENT)
		mlx->light = add_link(mlx->light, link);
	else
		mlx->obj = add_link(mlx->obj, link);
	return (0);
}

int				parse_objects(t_mlx *mlx)
{
	int			ret;
	char		*str;

	ret = 0;
	while (ft_strbetween_len(mlx->buff, "object", "}", 0) != NULL)
	{
		if ((str = ft_strstr(mlx->buff, "object(POINT)")))
			ret = ft_add_obj(mlx, str, POINT);
		else if ((str = ft_strstr(mlx->buff, "object(AMBIENT)")))
			ret = ft_add_obj(mlx, str, AMBIENT);
		else if ((str = ft_strstr(mlx->buff, "object(CONE)")))
			ret = ft_add_obj(mlx, str, CONE);
		else if ((str = ft_strstr(mlx->buff, "object(CYLINDER)")))
			ret = ft_add_obj(mlx, str, CYLINDER);
		else if ((str = ft_strstr(mlx->buff, "object(PLANE)")))
			ret = ft_add_obj(mlx, str, PLANE);
		else if ((str = ft_strstr(mlx->buff, "object(SPHERE)")))
			ret = ft_add_obj(mlx, str, SPHERE);
		if (ret == -1 || str == NULL)
			return (-1);
	}
	return (ret);
}
