/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_fractals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 21:38:10 by lsandor-          #+#    #+#             */
/*   Updated: 2019/03/03 14:50:21 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_random_fractal_two(t_args *a)
{
	t_helper h;

	h.x = -1;
	while (++h.x < W_WIDTH)
	{
		a->z.x = (h.x - a->m->x0) * a->m->sc_w - a->m->offx_h;
		h.z.x = a->z.x;
		h.z.y = a->z.y;
		h.i = -1;
		while ((++h.i <= MAX_ITERATIONS) && (h.z.x * h.z.x + h.z.y * h.z.y) < 20)
		{
			h.xtemp = h.z.x * h.z.x - h.z.y * h.z.y;
			h.z.y = tan(2 * h.z.x * h.z.y -0.4225);
			h.z.x = h.xtemp + 0.259;
		}
		if (h.i != MAX_ITERATIONS)
		{
			h.sqr_sum = sqrt(h.z.x * h.z.x + h.z.y * h.z.y);
			h.color = 255. * log2(2 + h.i - log2(log2(h.sqr_sum))) / log2((double)MAX_ITERATIONS);
			ft_set_pixel(a->m->add_ptr, h.x, a->y, ft_color(0, h.color,h.color));
		}
	}
}

void	ft_random_fractal_three(t_args *a)
{
	t_helper h;

	h.x = -1;
	while (++h.x < W_WIDTH)
	{
		a->z.x = (h.x - a->m->x0) * a->m->sc_w - a->m->offx_h;
		h.z.x = a->z.x;
		h.z.y = a->z.y;
		h.i = -1;
		while ((++h.i <= MAX_ITERATIONS) && (h.z.x * h.z.x + h.z.y * h.z.y) < 4)
		{
			h.xtemp = h.z.x * h.z.x - h.z.y * h.z.y;
			h.z.y = log2(2 * h.z.x * h.z.y + 1.110905);
			h.z.x = h.xtemp + 0.437077;
		}
		if (h.i != MAX_ITERATIONS)
		{
			h.sqr_sum = sqrt(h.z.x * h.z.x + h.z.y * h.z.y);
			h.color = 255. * log2(10 + h.i - log2(log2(h.sqr_sum))) / log2((double)MAX_ITERATIONS);
			ft_set_pixel(a->m->add_ptr, h.x, a->y, ft_color(0, h.color,h.color));
		}
	}
}

void	ft_random_fractal_four(t_args *a)
{
	t_helper h;

	h.x = -1;
	while (++h.x < W_WIDTH)
	{
		a->z.x = (h.x - a->m->x0) * a->m->sc_w - a->m->offx_h;
		h.z.x = a->z.x;
		h.z.y = a->z.y;
		h.i = -1;
		while ((++h.i <= MAX_ITERATIONS) && (h.z.x * h.z.x + h.z.y * h.z.y) < 4)
		{
			h.xtemp = h.z.x * h.z.x - h.z.y * h.z.y;
			h.z.y = log2(2 * h.z.x * h.z.y + 0.556250);
			h.z.x = log2(h.xtemp + 0.357000);
		}
		if (h.i != MAX_ITERATIONS)
		{
			h.sqr_sum = sqrt(h.z.x * h.z.x + h.z.y * h.z.y);
			h.color = 255. * log2(10 + h.i - log2(log2(h.sqr_sum))) / log2((double)MAX_ITERATIONS);
			ft_set_pixel(a->m->add_ptr, h.x, a->y, ft_color(0, h.color,h.color));
		}
	}
}

void	ft_random_fractal_five(t_args *a)
{
	t_helper h;

	h.x = -1;
	while (++h.x < W_WIDTH)
	{
		a->z.x = (h.x - a->m->x0) * a->m->sc_w - a->m->offx_h;
		h.z.x = a->z.x;
		h.z.y = a->z.y;
		h.i = -1;
		while ((++h.i <= MAX_ITERATIONS) && (h.z.x * h.z.x + h.z.y * h.z.y) < 4)
		{
			h.xtemp = h.z.x * h.z.x - h.z.y * h.z.y;
			h.z.y = h.z.x * h.z.y * h.z.y + 0.943452;
			h.z.x = h.xtemp + h.z.x * 0.424423;
		}
		if (h.i != MAX_ITERATIONS)
		{
			h.sqr_sum = sqrt(h.z.x * h.z.x + h.z.y * h.z.y);
			h.color = 255. * log2(10 + h.i - log2(log2(h.sqr_sum))) / log2((double)MAX_ITERATIONS);
			ft_set_pixel(a->m->add_ptr, h.x, a->y, ft_color(0, h.color,h.color));
		}
	}
}
