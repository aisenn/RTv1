/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <aabdulla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 22:01:43 by aabdulla          #+#    #+#             */
/*   Updated: 2019/02/07 22:01:49 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	keys(t_vec *tmp, int key)
{
	if (key == KEY_W)
		tmp->y = tmp->y + 0.1;
	else if (key == KEY_S)
		tmp->y = tmp->y - 0.1;
	else if (key == KEY_A)
		tmp->x = tmp->x - 0.1;
	else if (key == KEY_D)
		tmp->x = tmp->x + 0.1;
}

static void	arrow_keys(t_vec *tmp, int key, char *str)
{
	if (ft_strcmp("arrows", str) == 0)
	{
		if (key == UP)
			tmp->y = tmp->y + 0.1;
		else if (key == DOWN)
			tmp->y = tmp->y - 0.1;
		else if (key == LEFT)
			tmp->x = tmp->x - 0.1;
		else if (key == RIGHT)
			tmp->x = tmp->x + 0.1;
		else if (key == FORWARD)
			tmp->z = tmp->z + 1;
		else if (key == BACKWARD)
			tmp->z = tmp->z - 1;
	}
	else
		keys(tmp, key);
}

static void	choose_light(t_mlx *mlx, int key)
{
	int		type;
	t_obj	*i;

	if (key == TAB)
		mlx->info = 1;
	if (key == 18)
		type = AMBIENT;
	else
		type = POINT;
	i = mlx->light;
	while (i != NULL)
	{
		if (i->type == type)
			mlx->transfor = i;
		i = i->next;
	}
	mlx->ctrl->key = 0;
}

static void	choose_type(t_mlx *mlx, int key)
{
	if (key == 18 || key == 19 || key == TAB)
		choose_light(mlx, key);
	if (mlx->transfor != NULL)
	{
		arrow_keys(&mlx->transfor->rot, key, "wasd");
		arrow_keys(&mlx->transfor->pos, key, "arrows");
		if (mlx->transfor->type == AMBIENT || mlx->transfor->type == POINT)
		{
			if (key == KEY_MINUS)
				((mlx->transfor->intensity - 0.1) > 0) ?
				mlx->transfor->intensity -= 0.1 : mlx->transfor->intensity;
			if (key == KEY_PLUS)
				((mlx->transfor->intensity + 0.1) < 1) ?
				mlx->transfor->intensity += 0.1 : mlx->transfor->intensity;
		}
		else
		{
			if (key == KEY_MINUS)
				((mlx->transfor->size - 0.1) > 0.1) ?
				mlx->transfor->size -= 0.1 : mlx->transfor->size;
			if (key == KEY_PLUS)
				((mlx->transfor->size + 0.1) < 1000) ?
				mlx->transfor->size += 0.1 : mlx->transfor->size;
		}
	}
}

int			key_hook_on(int key, t_mlx *mlx)
{
	choose_type(mlx, key);
	if (key == ESC)
		exit(0);
	else if (key == KEY_C)
	{
		mlx->ctrl->key = key;
		mlx->transfor = NULL;
	}
	else if (key == KEY_R)
		mlx->r = (mlx->r ? 0 : 1);
	else if (key == KEY_F)
		mlx->s = (mlx->s ? 0 : 1);
	else if (mlx->ctrl->key == KEY_C)
	{
		arrow_keys(&mlx->cam_pos, key, "arrows");
		arrow_keys(&mlx->cam_dir, key, "wasd");
		if (key == KEY_PLUS)
			mlx->cam_pos.z = mlx->cam_pos.z + 1;
		else if (key == KEY_MINUS)
			mlx->cam_pos.z = mlx->cam_pos.z - 1;
	}
	draw(mlx);
	return (0);
}
