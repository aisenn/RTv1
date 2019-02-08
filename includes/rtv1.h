/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <aabdulla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:49:38 by aabdulla          #+#    #+#             */
/*   Updated: 2019/02/08 17:49:41 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "../libft/includes/libft.h"
# include "../libvec/libvec.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <pthread.h>

# define THREADS 4
# define WIDTH (800)
# define HEIGHT (400)
# define FOV 2.0

# define ESC 53
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define FORWARD 69
# define BACKWARD 78
# define KEY_A 0
# define KEY_D 2
# define KEY_S 1
# define KEY_W 13
# define KEY_C 8
# define KEY_MINUS 27
# define KEY_PLUS 24
# define KEY_R 15
# define KEY_F 3
# define TAB 48

typedef enum		e_type
{
	POINT,
	AMBIENT,
	SPHERE,
	PLANE,
	CYLINDER,
	CONE
}					t_type;

typedef struct		s_ctrl
{
	int				click;
	int				key;
	int				x;
	int				y;
	int				lastx;
	int				lasty;
}					t_ctrl;

typedef struct		s_obj
{
	int				type;
	t_vec			pos;
	t_vec			rot;
	t_vec			color;
	double			size;
	double			intensity;
	int				spec;
	double			refl;
	struct s_obj	*next;
}					t_obj;

typedef struct		s_mlx
{
	void			*win;
	void			*mlx;
	void			*img;
	char			*data;
	int				bpp;
	int				sl;
	int				end;
	char			*buff;
	t_ctrl			*ctrl;
	t_vec			cam_pos;
	t_vec			cam_dir;
	t_vec			ray_dir;
	t_obj			*obj;
	t_obj			*light;
	t_obj			*transfor;
	t_vec			norm;
	t_vec			view;
	double			t_min;
	double			t_max;
	int				depth;
	int				r;
	int				s;
	int				info;
}					t_mlx;

typedef	struct		s_elem
{
	t_mlx			*mlx;
	int				i;
}					t_elem;

int					parser(t_mlx *mlx);
int					parse_objects(t_mlx *mlx);
int					get_dimensions_var(t_vec *tmp, char **info);

void				draw(t_mlx *mlx);
t_vec				compute_lighting(t_mlx *mlx, t_vec p, t_obj *obj);
t_vec				obj_norm(t_obj *obj, t_vec pos, double m);
void				set_cam(t_mlx *mlx, double x, double y);
void				set_pixel(t_mlx *mlx, intmax_t x, intmax_t y, t_vec col);
t_vec				reflect(t_vec a, t_vec b);
t_vec				limit_color(t_vec vec);
t_vec				ray_trace(t_mlx *mlx, t_vec cam_pos,
					t_vec ray_dir, int depth);
t_obj				*closest_intersections(t_mlx *mlx, t_vec origin,
					t_vec ray_dir, double *t);
double				inter_sphere(t_vec origin, t_vec direction, t_obj *sphere);
double				inter_cylinder(t_vec origin, t_vec direction, t_obj *cyl);
double				inter_cone(t_vec origin, t_vec direction, t_obj *cone);
double				inter_plane(t_vec origin, t_vec direction, t_obj *plane);
int					key_hook_on(int key, t_mlx *mlx);
int					mouse_move(int x, int y, t_mlx *mlx);
int					mouse_click_on(int click, int x, int y, t_mlx *mlx);
int					mouse_click_off(int click, int x, int y, t_mlx *mlx);
int					close_button(void *close);
int					ft_error(char **str_to_del, char *message);
#endif
