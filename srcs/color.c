/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 13:12:03 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/15 16:57:00 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	double	ft_percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

static int		ft_get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int				ft_get_color(t_putline current, t_pixel start, t_pixel end)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.dx > current.dy)
		percentage = ft_percent(start.x, end.x, current.x);
	else
		percentage = ft_percent(start.y, end.y, current.y);
	red = ft_get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF,
			percentage);
	green = ft_get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF,
			percentage);
	blue = ft_get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
