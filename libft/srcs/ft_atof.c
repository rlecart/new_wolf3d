/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 06:03:24 by rlecart           #+#    #+#             */
/*   Updated: 2017/07/11 06:06:47 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

float	ft_atof(const char *str)
{
	float	n;
	int		i;
	int		k;
	int		sym;

	i = 0;
	n = 0;
	k = 0;
	sym = 1;
	if (!str)
		return (0);
	while (str[i] == ' ' || str[i] == '\v' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\f' || str[i] == '\n')
		i++;
	sym = (str[i] == '-') ? -sym : sym;
	i = (str[i] == '-' || str[i] == '+') ? i + 1 : i;
	while (str[i] > 47 && str[i] < 58)
	{
		n = n * 10 + (str[i++] - 48);
		if (str[i] == '.')
			k = i++;
	}
	while (k != 0 && str[++k])
		sym = sym * 10;
	return (n / sym);
}
