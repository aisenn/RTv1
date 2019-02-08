/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <aabdulla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 22:03:22 by aabdulla          #+#    #+#             */
/*   Updated: 2019/02/07 22:03:23 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		set_pixel(t_mlx *mlx, intmax_t x, intmax_t y, t_vec c)
{
	int		rgb;

	if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
	{
		rgb = (((int)c.x & 0x0ff) << 16) |
				(((int)c.y & 0x0ff) << 8) |
				((int)c.z & 0x0ff);
		*(int *)(mlx->data + ((x * mlx->bpp + y * mlx->sl))) = rgb;
	}
}

void		set_cam(t_mlx *mlx, double x, double y)
{
	t_vec	forward;
	t_vec	up;
	t_vec	right;

	x = (WIDTH - x * 2.0) / HEIGHT;
	y = (HEIGHT - y * 2.0) / HEIGHT;
	forward = ft_vecsub(mlx->cam_dir, (t_vec){0.0, 0.0, 0.0});
	ft_vecnorm(&forward);
	up = ft_veccross(forward, (t_vec){0.0, 1.0, 0.0});
	ft_vecnorm(&up);
	right = ft_vecmult(ft_veccross(up, forward), y);
	up = ft_vecmult(up, x);
	forward = ft_vecmult(forward, FOV);
	mlx->ray_dir = ft_vecadd(ft_vecadd(up, right), forward);
}

t_obj		*closest_intersections(t_mlx *mlx, t_vec origin,
		t_vec ray_dir, double *t)
{
	t_obj	*closest_obj;
	t_obj	*obj;
	double	ret;

	closest_obj = NULL;
	obj = mlx->obj;
	ret = 0;
	while (obj)
	{
		if (obj->type == SPHERE)
			ret = inter_sphere(origin, ray_dir, obj);
		else if (obj->type == PLANE)
			ret = inter_plane(origin, ray_dir, obj);
		else if (obj->type == CYLINDER)
			ret = inter_cylinder(origin, ray_dir, obj);
		else if (obj->type == CONE)
			ret = inter_cone(origin, ray_dir, obj);
		if (ret < *t && mlx->t_min < ret && ret < mlx->t_max)
		{
			*t = ret;
			closest_obj = obj;
		}
		obj = obj->next;
	}
	return (closest_obj);
}

t_vec		reflect(t_vec a, t_vec b)
{
	return (ft_vecsub(ft_vecmult(b, 2 * ft_vecdot(a, b)), a));
}

t_vec		ray_trace(t_mlx *mlx, t_vec origin, t_vec ray_dir, int depth)
{
	double	t;
	t_obj	*obj;
	t_vec	c;
	t_vec	p;
	double	m;

	t = mlx->t_max;
	if ((obj = closest_intersections(mlx, origin, ray_dir, &t)) == NULL)
		return ((t_vec){0, 0, 0});
	m = 0;
	if (obj->type == CONE || obj->type == CYLINDER)
	{
		m = ft_vecdot(ray_dir, obj->rot) * t + \
		ft_vecdot(ft_vecsub(origin, obj->pos), obj->rot);
	}
	p = ft_vecadd(origin, ft_vecmult(ray_dir, t));
	mlx->view = ft_vecmult(ray_dir, -1);
	mlx->norm = obj_norm(obj, p, m);
	c = compute_lighting(mlx, p, obj);
	if (obj->refl <= 0 || depth <= 0 || !mlx->r)
		return (c);
	mlx->t_min = 0.001;
	p = ray_trace(mlx, p, reflect(mlx->view, mlx->norm), depth - 1);
	return (ft_vecadd(ft_vecmult(c, 1 - obj->refl), ft_vecmult(p, obj->refl)));
}
