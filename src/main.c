/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <aabdulla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 22:01:23 by aabdulla          #+#    #+#             */
/*   Updated: 2019/02/07 22:01:27 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static char		*getbuff(char *s)
{
	int			fd;
	char		*buff;

	if ((fd = open(s, O_RDONLY)) == -1)
	{
		ft_putendl("error to open");
		return (NULL);
	}
	if ((buff = ft_get_file_content(fd, 0)) == NULL)
	{
		ft_putendl("error to read");
		ft_strdel(&buff);
		return (NULL);
	}
	if (close(fd) == -1)
	{
		ft_putendl("error to close");
		ft_strdel(&buff);
		return (NULL);
	}
	return (buff);
}

static int		init_mlx(t_mlx *mlx, char *argv)
{
	char		*name;

	if ((mlx->buff = getbuff(argv)) == NULL)
		return (-1);
	mlx->obj = NULL;
	mlx->light = NULL;
	if (parser(mlx) == -1)
		return (ft_error(&mlx->buff, NULL));
	if ((name = ft_strjoin_free("RTv1: ", argv, 'N')) == NULL)
		return (-1);
	if ((mlx->ctrl = (t_ctrl *)malloc(sizeof(t_ctrl))) == NULL)
		return (-1);
	mlx->mlx = mlx_init();
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, name);
	free(name);
	mlx->data = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sl, &mlx->end);
	mlx->bpp /= 8;
	mlx->t_min = 1;
	mlx->t_max = 1000;
	mlx->depth = 3;
	mlx->transfor = NULL;
	mlx->r = 0;
	mlx->s = 0;
	return (0);
}

int				main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc != 2)
	{
		ft_putendl("Usage: ./rtv1 input_file");
		return (0);
	}
	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (0);
	if (init_mlx(mlx, argv[1]) == -1)
	{
		free(mlx);
		return (0);
	}
	mlx->info = 1;
	draw(mlx);
	mlx_hook(mlx->win, 2, 0, key_hook_on, mlx);
	mlx_hook(mlx->win, 4, 0, mouse_click_on, mlx);
	mlx_hook(mlx->win, 5, 0, mouse_click_off, mlx);
	mlx_hook(mlx->win, 6, 0, mouse_move, mlx);
	mlx_hook(mlx->win, 17, 0, close_button, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
