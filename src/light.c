/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <aabdulla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 22:01:05 by aabdulla          #+#    #+#             */
/*   Updated: 2019/02/07 22:01:08 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec			limit_color(t_vec vec)
{
	vec.x = ft_min(255, ft_max(0, vec.x));
	vec.y = ft_min(255, ft_max(0, vec.y));
	vec.z = ft_min(255, ft_max(0, vec.z));
	return (vec);
}

t_vec			obj_norm(t_obj *obj, t_vec pos, double m)
{
	t_vec		norm;

	if (obj->type == CONE || obj->type == CYLINDER)
		norm = ft_vecsub(ft_vecsub(pos, obj->pos), ft_vecmult(obj->rot, m));
	else if (obj->type == PLANE)
		norm = obj->rot;
	if (obj->type == SPHERE)
		norm = ft_vecsub(pos, obj->pos);
	ft_vecnorm(&norm);
	return (norm);
}

static double	specular_light(int spec, double intens, t_vec vec_r, t_vec view)
{
	double		reflect_v;
	double		len_v;

	len_v = ft_veclength(view);
	reflect_v = ft_vecdot(vec_r, view);
	if (reflect_v > 0)
		return (intens * pow(reflect_v / (ft_veclength(vec_r) * len_v), spec));
	return (0);
}

static double	lights(t_mlx *mlx, t_obj *light, t_vec p, t_vec vec_l)
{
	double		dot_l;
	double		len_n;

	len_n = ft_veclength(mlx->norm);
	mlx->t_min = 0.001;
	if (closest_intersections(mlx, p, vec_l, &(double){1}) == NULL)
	{
		dot_l = ft_vecdot(mlx->norm, vec_l);
		if (dot_l > 0)
			return (light->intensity * dot_l / (len_n * ft_veclength(vec_l)));
	}
	return (0);
}

t_vec			compute_lighting(t_mlx *mlx, t_vec p, t_obj *obj)
{
	double		intensity;
	t_obj		*light;
	t_vec		vec_l;

	intensity = 0;
	light = mlx->light;
	while (light)
	{
		if (light->type == AMBIENT)
			intensity += light->intensity;
		else
		{
			vec_l = ft_vecsub(light->pos, p);
			if ((intensity += lights(mlx, light, p, vec_l)))
				if (obj->spec != -1 && mlx->s)
				{
					intensity += specular_light(obj->spec, light->intensity,
					reflect(vec_l, mlx->norm), mlx->view);
				}
		}
		light = light->next;
	}
	return (ft_vecmult(obj->color, intensity));
}
