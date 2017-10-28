/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 06:22:53 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/14 03:34:36 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char		*j;

	j = (unsigned char*)s;
	while (n-- != 0)
		*j++ = 0;
}
