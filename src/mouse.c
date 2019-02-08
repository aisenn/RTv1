/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <aabdulla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 22:02:02 by aabdulla          #+#    #+#             */
/*   Updated: 2019/02/07 22:02:05 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			mouse_move(int x, int y, t_mlx *mlx)
{
	t_obj	*tmp;

	mlx->ctrl->lastx = mlx->ctrl->x;
	mlx->ctrl->lasty = mlx->ctrl->y;
	mlx->ctrl->x = x;
	mlx->ctrl->y = y;
	if (mlx->ctrl->click && mlx->transfor != NULL)
	{
		tmp = mlx->transfor;
		tmp->pos.y += (mlx->ctrl->lasty - y) * 0.1;
		tmp->pos.x -= (mlx->ctrl->lastx - x) * 0.1;
	}
	if (mlx->ctrl->click)
		draw(mlx);
	return (0);
}

int			mouse_click_on(int click, int x, int y, t_mlx *mlx)
{
	double	t;

	if (!mlx->ctrl->click && click == 1)
	{
		mlx->ctrl->click = 1;
		set_cam(mlx, x, y);
		t = 1000;
		mlx->transfor = closest_intersections(mlx, mlx->cam_pos,
				mlx->ray_dir, &t);
		if (mlx->transfor != NULL)
			mlx->ctrl->key -= mlx->ctrl->key;
	}
	if (mlx->ctrl->click && click == 5 && mlx->transfor != NULL)
		mlx->transfor->pos.z -= 1;
	else if (mlx->ctrl->click && click == 4 && mlx->transfor != NULL)
		mlx->transfor->pos.z += 1;
	if (mlx->ctrl->click)
		draw(mlx);
	return (0);
}

int			mouse_click_off(int click, int x, int y, t_mlx *mlx)
{
	(void)click;
	(void)x;
	(void)y;
	mlx->ctrl->click -= mlx->ctrl->click;
	mlx->ctrl->key = 0;
	return (0);
}

int			close_button(void *close)
{
	if (close != NULL)
		exit(0);
	return (0);
}
