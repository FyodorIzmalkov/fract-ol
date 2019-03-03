/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 23:56:32 by lsandor-          #+#    #+#             */
/*   Updated: 2019/03/03 22:12:42 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_color(unsigned char red, unsigned char green, unsigned char blue)
{
	int color;

	color = color >> 16 | red;
	color = color << 8 | green;
	color = color << 8 | blue;
	return (color);
}

int	ft_clr(t_helper *h, char set)
{
	unsigned char color;

	h->sqr_sum = sqrt(h->z_2.y + h->z_2.x);
	color = 255. * log2(4 + h->i - log2(log2(h->sqr_sum))) /
		log2((double)h->iter);
	if (set == 0)
		return (ft_color(0, color, color));
	else if (set == 1)
		return (ft_color(color, 10, 0));
	else if (set == 2)
		return (ft_color(color, 0, color));
	else if (set == 3)
		return (ft_color(0, color, 0));
	else if (set == 4)
		return (ft_color(color, color, 0));
	else if (set == 5)
		return (ft_color(0, 0, color));
	else if (set == 6)
		return (ft_color(10, color, 150));
	else if (set == 7)
		return (ft_color(color, 20, 130));
	else if (set == 8)
		return (ft_color(35, 2, color));
	return (0x00FFFFFF);
}
