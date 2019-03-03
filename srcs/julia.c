/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 20:38:05 by lsandor-          #+#    #+#             */
/*   Updated: 2019/03/03 14:48:33 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia(t_args *a)
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
			h.z.y = 2 * h.z.x * h.z.y + a->m->cury;
			h.z.x = h.xtemp + a->m->curx;
		}
		if (h.i != MAX_ITERATIONS)
		{
			h.sqr_sum = sqrt(h.z.x * h.z.x + h.z.y * h.z.y);
			h.color = 255. * log2(2 + h.i - log2(log2(h.sqr_sum))) / log2((double)MAX_ITERATIONS);
			ft_set_pixel(a->m->add_ptr, h.x, a->y, ft_color(0, h.color,h.color));
		}
	}
}
