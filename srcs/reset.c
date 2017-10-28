/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 11:40:06 by rlecart           #+#    #+#             */
/*   Updated: 2017/10/28 19:47:06 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	loop_color(char *data, t_color color, int len)
{
	int		i;

	i = -1;
	while (++i < len)
		((t_color*)data)[i] = color;
}

void	reset_image(t_env *e)
{
	int			add;
	t_color		c1;
	t_color		c2;

	c1 = get_color(252, 188, 85, 0);
	c2 = get_color(71, 71, 71, 0);
	add = WIN_W * WIN_H / 2;
	loop_color(IMG.data, c1, add);
	loop_color(IMG.data + add * sizeof(int), c2, add);
}
