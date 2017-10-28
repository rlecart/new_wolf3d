/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 05:13:14 by rlecart           #+#    #+#             */
/*   Updated: 2017/10/28 19:46:24 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/includes/libft.h"
# include "../graphics/includes/graphics.h"

typedef struct		s_v2d
{
	double			x;
	double			y;
}					t_v2d;

typedef struct		s_v2i
{
	int				x;
	int				y;
}					t_v2i;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_color			pix;
	int				map[20][20];
	t_v2d			pos;
	t_v2d			dir;
	t_v2d			plane;
	double			cam;
	t_v2d			vpos;
	t_v2d			vdir;
	t_v2i			vmap;
	t_v2d			vstep;
	int				hit;
	int				side;
	t_v2d			side_dist;
	t_v2d			d_dist;
	double			per;
	int				line_height;
	int				up;
	int				down;
}					t_env;

void				init(t_env *e);
void				raycasting(t_env *e);
void				reset_image(t_env *e);
int					key_hook(int keycode, t_env *e);
int					exit_hook(void);

#endif
