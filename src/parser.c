/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <aabdulla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 22:02:20 by aabdulla          #+#    #+#             */
/*   Updated: 2019/02/07 22:02:23 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				ft_error(char **str_to_del, char *message)
{
	if (str_to_del != NULL)
		ft_strdel(str_to_del);
	if (message != NULL)
		ft_putendl(message);
	return (-1);
}

int				get_dimensions_var(t_vec *tmp, char **info)
{
	char		**vars;

	if (info)
	{
		if (ft_count_words(*info) != 3)
			return (ft_error(info, "Not three variables set"));
		if ((vars = ft_strsplit(*info, ' ')) == 0)
			return (ft_error(info, "split error"));
		tmp->x = ft_atoi(vars[0]);
		tmp->y = ft_atoi(vars[1]);
		tmp->z = ft_atoi(vars[2]);
		ft_strdel(info);
		ft_str2del(&vars);
	}
	else
		ft_error(NULL, "Error");
	return (0);
}

static int		parse_cam(t_mlx *mlx)
{
	char		*str;

	if ((str = ft_strbetween_sub(mlx->buff, "scene\n{", "}")) == NULL)
		return (-1);
	if (ft_count_printable_str(str) != 2)
		return (ft_error(&str, "More then two property for camera"));
	ft_strdel(&str);
	if ((str = ft_strbetween_sub(mlx->buff, "cam_pos(", ")")) == NULL)
		return (-1);
	if ((get_dimensions_var(&mlx->cam_pos, &str)) == -1)
		return (-1);
	if ((str = ft_strbetween_sub(mlx->buff, "cam_dir(", ")")) == NULL)
		return (-1);
	if ((get_dimensions_var(&mlx->cam_dir, &str)) == -1)
		return (-1);
	return (0);
}

int				parser(t_mlx *mlx)
{
	if (ft_brackets(mlx->buff) == 0)
		return (ft_error(NULL, "Brackets error"));
	if (ft_strbetween_len(mlx->buff, "scene\n{", "}", 0) == NULL)
		return (ft_error(NULL, "error: scene is not set"));
	if ((ft_strstr(mlx->buff, "object(POINT)") == NULL) &&
		(ft_strstr(mlx->buff, "object(AMBIENT)") == NULL))
		return (ft_error(NULL, "error: light is not set"));
	if ((ft_strstr(mlx->buff, "object(SPHERE)") == NULL) &&
		(ft_strstr(mlx->buff, "object(PLANE)") == NULL) &&
		(ft_strstr(mlx->buff, "object(CYLINDER)") == NULL) &&
		(ft_strstr(mlx->buff, "object(CONE)") == NULL))
		return (ft_error(NULL, "error: object is not set"));
	if (parse_cam(mlx) == -1)
		return (-1);
	if (parse_objects(mlx) == -1)
		return (-1);
	return (0);
}
