/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 05:41:32 by rlecart           #+#    #+#             */
/*   Updated: 2017/10/28 19:46:58 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int		main(void)
{
	t_env	e;

	init(&e);
	raycasting(&e);
	mlx_loop(e.mlx);
	return (0);
}
