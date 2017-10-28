/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 19:00:44 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/02 19:06:16 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <graphics.h>

void	reset_img(char *data, int x_max, int y_max)
{
	int			x;
	int			y;
	t_color		pix;

	x = 0;
	y = 0;
	pix = get_color(0, 0, 0, 0);
	while (y < y_max)
	{
		while (x < x_max)
		{
			pixel_put(data, x, y, pix);
			x++;
		}
		x = 0;
		y++;
	}
}
