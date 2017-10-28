/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 06:35:15 by rlecart           #+#    #+#             */
/*   Updated: 2017/10/28 20:09:32 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int		exit_hook(void)
{
	exit(0);
	return (0);
}

void	key_hook_sequel(int keycode, t_env *e)
{
	double	tmp_dir;
	double	tmp_plane;

	if (keycode == LEFT)
	{
		tmp_dir = e->dir.x;
		e->dir.x = e->dir.x * cos(0.157) - e->dir.y * sin(0.157);
		e->dir.y = tmp_dir * sin(0.157) + e->dir.y * cos(0.157);
		tmp_plane = e->plane.x;
		e->plane.x = e->plane.x * cos(0.157) - e->plane.y * sin(0.157);
		e->plane.y = tmp_plane * sin(0.157) + e->plane.y * cos(0.157);
	}
	else if (keycode == RIGHT)
	{
		tmp_dir = e->dir.x;
		e->dir.x = e->dir.x * cos(-0.157) - e->dir.y * sin(-0.157);
		e->dir.y = tmp_dir * sin(-0.157) + e->dir.y * cos(-0.157);
		tmp_plane = e->plane.x;
		e->plane.x = e->plane.x * cos(-0.157) - e->plane.y * sin(-0.157);
		e->plane.y = tmp_plane * sin(-0.157) + e->plane.y * cos(-0.157);
	}
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == UP)
	{
		if (!e->map[(int)(e->pos.x + e->dir.x)][(int)e->pos.y])
			e->pos.x += e->dir.x * 0.5;
		if (!e->map[(int)e->pos.x][(int)(e->pos.y + e->dir.y)])
			e->pos.y += e->dir.y * 0.5;
	}
	else if (keycode == DOWN)
	{
		if (!e->map[(int)(e->pos.x - e->dir.x)][(int)e->pos.y])
			e->pos.x -= e->dir.x * 0.5;
		if (!e->map[(int)e->pos.x][(int)(e->pos.y - e->dir.y)])
			e->pos.y -= e->dir.y * 0.5;
	}
	else
		key_hook_sequel(keycode, e);
	if (keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT)
		raycasting(e);
	return (0);
}
