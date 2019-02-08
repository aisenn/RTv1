/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <aabdulla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 22:02:53 by aabdulla          #+#    #+#             */
/*   Updated: 2019/02/07 22:02:57 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		ft_copy(t_mlx *mlx, t_mlx *th)
{
	th->cam_pos = mlx->cam_pos;
	th->cam_dir = mlx->cam_dir;
	th->ray_dir = mlx->ray_dir;
	th->light = mlx->light;
	th->obj = mlx->obj;
	th->bpp = mlx->bpp;
	th->sl = mlx->sl;
	th->data = mlx->data;
	th->t_min = mlx->t_min;
	th->t_max = mlx->t_max;
	th->depth = mlx->depth;
	th->r = mlx->r;
	th->s = mlx->s;
}

static void		*thread_process(void *arg)
{
	t_mlx		*th;
	int			x;
	int			y;
	t_vec		col;
	t_elem		*elem;

	elem = (t_elem*)arg;
	if ((th = (t_mlx *)malloc(sizeof(t_mlx))))
	{
		ft_copy(elem->mlx, th);
		y = -1;
		while (++y < HEIGHT)
		{
			x = WIDTH * elem->i / THREADS;
			while (x < WIDTH * (elem->i + 1) / THREADS)
			{
				set_cam(th, x, y);
				col = ray_trace(th, th->cam_pos, th->ray_dir, th->depth);
				set_pixel(th, x, y, limit_color(col));
				x++;
			}
		}
		free(th);
	}
	pthread_exit(0);
}

static char		*detect_obj(int type)
{
	if (type == SPHERE)
		return ("object(SPHERE)");
	else if (type == PLANE)
		return ("object(PLANE)");
	else if (type == CYLINDER)
		return ("object(CYLINDER)");
	else if (type == CONE)
		return ("object(CONE)");
	else if (type == 8)
		return ("object(CAMERA)");
	else if (type == AMBIENT)
		return ("light(AMBIENT)");
	else if (type == POINT)
		return ("light(SPOT)");
	return ("");
}

static void		information(t_mlx *mlx)
{
	if (mlx->ctrl->key != 0)
		mlx_string_put(mlx->mlx, mlx->win, 5, 0, 0xFFFF,
				detect_obj(mlx->ctrl->key));
	else if (mlx->transfor)
		mlx_string_put(mlx->mlx, mlx->win, 5, 0, 0xFFFF,
				detect_obj(mlx->transfor->type));
	if (!mlx->info)
		return ;
	ft_putendl("                  --- CONTROLS ---");
	ft_putendl("*******************************************************");
	ft_putendl("*  left click:  select object                         *");
	ft_putendl("*  1/2:         select light [ AMBIENT | SPOT ]       *");
	ft_putendl("*  w a s d:     rotate camera/object                  *");
	ft_putendl("*  <^>(arrows): move camera/object/light              *");
	ft_putendl("*  +/-(num):    move camera/object/light along z axis *");
	ft_putendl("*  +/-:         increase/decrease size for objects    *");
	ft_putendl("*  +/-:         increase/decrease intensity for light *");
	ft_putendl("*  F:           activate/deactivate gloss             *");
	ft_putendl("*  R:           activate/deactivate reflection        *");
	ft_putendl("*  ESC:         exit                                  *");
	ft_putendl("*******************************************************");
	mlx->info = 0;
}

void			draw(t_mlx *mlx)
{
	pthread_t	th[THREADS];
	t_elem		elem[THREADS];
	void		*ret;
	int			i;

	i = -1;
	mlx_clear_window(mlx, mlx->win);
	while (++i < THREADS)
	{
		elem[i].mlx = mlx;
		elem[i].i = i;
		pthread_create(&th[i], NULL, thread_process, &elem[i]);
	}
	i = -1;
	while (++i < THREADS)
		pthread_join(th[i], &ret);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	information(mlx);
}
