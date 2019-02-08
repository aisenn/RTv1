/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulla <aabdulla@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:30:25 by aabdulla          #+#    #+#             */
/*   Updated: 2019/02/08 16:31:09 by aabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVEC_H
# define LIBVEC_H

# include <math.h>

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

void				ft_vecnorm(t_vec *vec);
double				ft_veclength(t_vec vec);
double				ft_vecdot(t_vec a, t_vec b);
t_vec				ft_veccross(t_vec a, t_vec b);
t_vec				ft_vecsub(t_vec a, t_vec b);
t_vec				ft_vectransfor(t_vec v);
t_vec				ft_vecadd(t_vec a, t_vec b);
t_vec				ft_vecmult(t_vec v, double scalar);

#endif
