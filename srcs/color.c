/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 23:56:32 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/26 00:18:01 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_choose_color(t_fractol *f, int x, int y, int iter)
{
	float percent;
	int color_start;
	int color_end;
	int color;
	int color_part;

	if (iter <= (MAX_ITERATIONS / 2 - 1))
	{
		percent = iter / ((MAX_ITERATIONS >> 1) -1);
		color_start = 0x000000;
		color_end = 0xFF0000;
		color_part = color_end / (MAX_ITERATIONS / 2 - 1);
		color = color_start + color_part * iter;
		ft_set_pixel(f, x, y, color);
	}
	else
	{
		percent = iter / MAX_ITERATIONS;
		color_start = 0xFF0000;
		color_end = 0xFFFFFF;
		color = color_end * percent;
		ft_set_pixel(f, x, y, color);
	}
}
