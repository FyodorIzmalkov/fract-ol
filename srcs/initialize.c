/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 22:54:43 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/15 16:59:03 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_get_iso_scale(t_fdf *fdf)
{
	double x;
	double y;

	x = sqrt(fdf->col * fdf->col + fdf->row * fdf->row - fdf->col * fdf->row);
	y = sqrt(fdf->col * fdf->col + fdf->row * fdf->row + fdf->col * fdf->row);
	y = fdf->options->z0 > y ? fdf->options->z0 + y : y;
	x = W_WIDTH / x * 0.9;
	y = W_HEIGHT / y * 0.9;
	fdf->options->iso_scale = x > y ? y : x;
}

void		ft_initialize_fdf(t_fdf *fdf)
{
	ft_display_error(!(fdf->options = ft_memalloc(sizeof(t_options))), 3);
	ft_display_error(!(fdf->image = ft_memalloc(sizeof(t_img))), 3);
	fdf->options->min = 2147483647;
	fdf->options->max = -2147483648;
	fdf->options->z0 = 0.0;
	fdf->options->x = 200;
	fdf->col = -1;
	fdf->row = 0;
	fdf->decreaser = 2;
	fdf->color = 0x077F11;
	fdf->color_changer = 1;
	fdf->lines = NULL;
	fdf->drawn = NULL;
	fdf->options->size = 1;
	fdf->angle.x = 0.0;
	fdf->angle.y = 0.0;
	fdf->angle.z = 0.0;
	fdf->options->proection = 0;
	fdf->options->horiz = 0;
	fdf->options->vertic = 0;
	fdf->options->altitude = 0;
	fdf->mouse.pressed = 0;
	fdf->mouse.draw_button = 0;
}

void		ft_initialize_map(t_fdf *fdf)
{
	int minimal;

	if (fdf->options->min < 0)
		minimal = -fdf->options->min;
	else
		minimal = fdf->options->min;
	fdf->options->z0 = fdf->options->max + minimal;
	fdf->options->x0 = fdf->col >> 1;
	fdf->options->y0 = fdf->row >> 1;
	ft_get_iso_scale(fdf);
}

void		ft_set_defaults(t_fdf *fdf)
{
	fdf->angle.x = 0.0;
	fdf->angle.y = 0.0;
	fdf->angle.z = 0.0;
	fdf->options->size = 1;
	fdf->options->horiz = 0;
	fdf->options->vertic = 0;
	fdf->options->altitude = 0;
	fdf->options->x = 200;
	fdf->decreaser = 2;
	fdf->color = 0x077F11;
	fdf->color_changer = 1;
}
