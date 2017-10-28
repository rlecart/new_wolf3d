/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 15:20:07 by rlecart           #+#    #+#             */
/*   Updated: 2017/10/28 20:13:35 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <float.h>
# include "../../minilibx_macos/mlx.h"

# define WIN_W		1280
# define WIN_H		720

# define MLX e->mlx
# define WIN e->win
# define IMG e->img

# define ESC		53
# define BACKSPACE	51
# define SPACE		49
# define LSHIFT		257
# define ENTER		36
# define KEY_1		18
# define KEY_2		19
# define KEY_3		20
# define KEY_4		21
# define PLUS		69
# define MINUS		78
# define UP			126
# define DOWN		125
# define LEFT		123
# define RIGHT		124
# define PAGE_UP	116
# define PAGE_DOWN	121
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2

# define PI			3.14159265

typedef struct		s_color
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}					t_color;

typedef struct		s_img
{
	void			*img;
	char			*data;
	int				bpp;
	int				size_l;
	int				endian;
}					t_img;

typedef struct		s_v3f
{
	float			x;
	float			y;
	float			z;
}					t_v3f;

void				pixel_put(char *data, int x, int y, t_color pix);
void				reset_img(char *data, int x_max, int y_max);
void				add_3f(float (*a)[3], float (*b)[3], float (*c)[3]);
void				mul_3f(float (*a)[3], float (*b)[3], float (*c)[3]);
t_color				get_color(int b, int g, int r, int a);
t_v3f				get_vector(int x, int y, float dir[3]);

#endif
