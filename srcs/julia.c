/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 20:38:05 by lsandor-          #+#    #+#             */
/*   Updated: 2019/03/03 19:04:36 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia(t_args *a)
{
	t_helper h;

	h.x = -1;
	while (++h.x < W_WIDTH)
	{
		h.zx = (h.x - a->m->x0) * a->m->sc_w - a->m->offx_h - a->m->x1;
		h.z.x = h.zx;
		h.z.y = a->zy;
		h.i = -1;
		while ((++h.i <= MAX_ITERATIONS) && (h.z.x * h.z.x + h.z.y * h.z.y) < 20)
		{
			h.xtemp = h.z.x * h.z.x - h.z.y * h.z.y;
			h.z.y = 2 * h.z.x * h.z.y + a->m->cury;
			h.z.x = h.xtemp + a->m->curx;
		}
		h.z_2.y = h.z.y * h.z.y;
		h.z_2.x = h.z.x * h.z.x;
		if (h.i != MAX_ITERATIONS)
			*(int *)(a->m->add_ptr + (h.x + a->y * W_WIDTH) * 4) = ft_clr(&h, a->m->set);
	}
}
