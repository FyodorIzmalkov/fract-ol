/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 23:56:32 by lsandor-          #+#    #+#             */
/*   Updated: 2019/03/01 19:04:30 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

static int		ft_get_color(double percentage, int start, int end)
{
	int		red;
	int		green;
	int		blue;

	percentage = percentage * (MAX_ITERATIONS / 20);
	red = ft_get_light((start >> 16) & 0xFF, (end >> 16) & 0xFF,
			percentage);
	green = ft_get_light((start >> 8) & 0xFF, (end >> 8) & 0xFF,
			percentage);
	blue = ft_get_light(start & 0xFF, end & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

void	ft_choose_color(char *add_ptr, int x, int y, double iter)
{
	double percent;
	int color_start;
	int color_end;
	int color;
	int color_part;

	if (iter <= (MAX_ITERATIONS >> 1) - 1)
	{
		percent = iter / (double)((MAX_ITERATIONS >> 1) -1);
		color_start = 0x000000;
		color_end = 0xFF0000;
		//color = (int)(color_end * percent);
		ft_set_pixel(add_ptr, x, y, ft_get_color(percent, color_start, color_end));
	}
	else
	{
		percent = iter / (double)MAX_ITERATIONS;
		color_start = 0xFF0000;
		color_end = 0xFFFFFF;
		color = (int)(color_end * percent);
		ft_set_pixel(add_ptr, x, y, ft_get_color(percent, color_start, color_end));
	}
}
