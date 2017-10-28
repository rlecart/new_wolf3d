/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 06:42:26 by rlecart           #+#    #+#             */
/*   Updated: 2017/10/28 19:47:18 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	calc(t_env *e, int x)
{
	e->cam = 2 * x / (double)WIN_W - 1;
	e->vpos.x = e->pos.x;
	e->vpos.y = e->pos.y;
	e->vdir.x = e->dir.x + e->plane.x * e->cam;
	e->vdir.y = e->dir.y + e->plane.y * e->cam;
	e->d_dist.x = sqrtf(1 + (e->vdir.y * e->vdir.y) / (e->vdir.x * e->vdir.x));
	e->d_dist.y = sqrtf(1 + (e->vdir.x * e->vdir.x) / (e->vdir.y * e->vdir.y));
	e->vmap.x = (int)e->vpos.x;
	e->vmap.y = (int)e->vpos.y;
	e->hit = 0;
}

void	hit_loop(t_env *e)
{
	while (e->hit == 0)
	{
		if (e->side_dist.x < e->side_dist.y)
		{
			e->side_dist.x += e->d_dist.x;
			e->vmap.x += e->vstep.x;
			e->side = 0;
		}
		else
		{
			e->side_dist.y += e->d_dist.y;
			e->vmap.y += e->vstep.y;
			e->side = 1;
		}
		if (e->map[e->vmap.x][e->vmap.y] > 0)
			e->hit = 1;
	}
}

void	walls(t_env *e)
{
	if (e->side == 0)
		e->per = (e->vmap.x - e->vpos.x + (1 - e->vstep.x) / 2) / e->vdir.x;
	else
		e->per = (e->vmap.y - e->vpos.y + (1 - e->vstep.y) / 2) / e->vdir.y;
	e->line_height = (int)(WIN_H / e->per);
	e->up = -e->line_height / 2 + WIN_H / 2;
	if (e->up < 0)
		e->up = 0;
	e->down = e->line_height / 2 + WIN_H / 2;
	if (e->down > WIN_H)
		e->down = WIN_H;
	if (e->side == 0)
		e->pix = get_color(0, 165, 71, 0);
	else if (e->side == 1)
		e->pix = get_color(0, 200, 142, 0);
	if ((e->side == 1 && e->vdir.y > 0) || (e->side == 0 && e->vdir.x < 0))
		e->pix =
			get_color(e->pix.b / 1.5, e->pix.g / 1.5, e->pix.r / 1.5, e->pix.a);
}

void	line(int x, int up, int down, t_env *e)
{
	while (up < down)
		pixel_put(e->img.data, x, up++, e->pix);
}

void	raycasting(t_env *e)
{
	int		x;

	x = 0;
	reset_image(e);
	while (x < WIN_W)
	{
		calc(e, x);
		if (e->vdir.x < 0 && (e->vstep.x = -1))
			e->side_dist.x = (e->vpos.x - e->vmap.x) * e->d_dist.x;
		else if ((e->vstep.x = 1))
			e->side_dist.x = (e->vmap.x + 1.0 - e->vpos.x) * e->d_dist.x;
		if (e->vdir.y < 0 && (e->vstep.y = -1))
			e->side_dist.y = (e->vpos.y - e->vmap.y) * e->d_dist.y;
		else if ((e->vstep.y = 1))
			e->side_dist.y = (e->vmap.y + 1.0 - e->vpos.y) * e->d_dist.y;
		hit_loop(e);
		walls(e);
		line(x, e->up, e->down, e);
		x++;
	}
	mlx_put_image_to_window(MLX, WIN, IMG.img, 0, 0);
}
