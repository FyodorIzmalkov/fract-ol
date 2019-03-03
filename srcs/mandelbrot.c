/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 22:29:34 by lsandor-          #+#    #+#             */
/*   Updated: 2019/03/03 15:05:22 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
	
void	ft_mandelbrot(t_args *a)
{
	t_helper h;

	h.x = -1;
	while (++h.x < W_WIDTH)
	{
		h.zx = (h.x - a->m->x0) * a->m->sc_w - a->m->offx_h;
		h.z.x = h.zx;
		h.z.y = a->zy;
		h.z_2.x = h.z.x * h.z.x;
		h.z_2.y = h.z.y * h.z.y;
		h.i = -1;
		while ((++h.i < MAX_ITERATIONS) && (h.z_2.x + h.z_2.y) < 4)
		{
			h.z.y = 2 * h.z.x * h.z.y + a->zy;
			h.z.x = h.z_2.x - h.z_2.y + h.zx;
			h.z_2.x = h.z.x * h.z.x;
			h.z_2.y = h.z.y * h.z.y;
		}
		if (h.i != MAX_ITERATIONS)
		{
			h.sqr_sum = sqrt(h.z_2.y + h.z_2.x);
			h.color = 255. * log2(2 + h.i - log2(log2(h.sqr_sum))) / log2((double)MAX_ITERATIONS);
			ft_set_pixel(a->m->add_ptr, h.x, a->y, ft_color(0, h.color, h.color));
		}
	}
}
