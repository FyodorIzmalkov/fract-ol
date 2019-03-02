/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 22:29:34 by lsandor-          #+#    #+#             */
/*   Updated: 2019/03/02 19:08:40 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	ft_init_mondelbrot(t_mondel *m, t_fractol *f)
{
	m->min_re = -2.0;
	m->max_re = 1.0;
	m->min_im = -1.2;
	m->max_im = m->min_im + (m->max_re - m->min_re) * W_HEIGHT / W_WIDTH;
	m->re_factor = (m->max_re - m->min_re) / (W_WIDTH - 1);
	m->im_factor = (m->max_im - m->min_im) / (W_HEIGHT - 1);
	m->y = -1;
	m->z_re = 0;
	m->z_im = 0;
	m->x0 = f->x0;
	m->y0 = f->y0;
	m->offsetx = f->offsetx;
	m->offsety = f->offsety;
	m->scale = f->scale;
}

/*void	ft_mandelbrot_fractol(t_fractol *f)
{
	t_mondel m;
	pthread_t threads[NTHREADS];
	t_thread thread_args[NTHREADS];
	int i;
	int y;

	y = 0;
	i = -1;
	ft_init_mondelbrot(&m, f);
	while (++i < NTHREADS)
	{
		if (i)
			i % 2 == 0 ? y++ : 0;
		thread_args[i].st = y;
		if (i % 2 == 0)
		{
			thread_args[i].stx = 0;
			thread_args[i].endx = (W_WIDTH >> 1);
		}
		else
		{
			thread_args[i].stx = (W_WIDTH >> 1);
			thread_args[i].endx = W_WIDTH;
		}
		thread_args[i].end = y;
		thread_args[i].mon = m;
		thread_args[i].add_ptr = f->add_ptr;
		pthread_create(&threads[i], NULL, ft_calculate, (void*)&thread_args[i]);
	}
	i = -1;
	while (++i < NTHREADS)
	{
		pthread_join(threads[i], NULL);
	}
}*/
	
void	ft_mandelbrot(t_args *a, char *add_ptr)
{
	t_helper h;

	while (++a->x < W_WIDTH)
	{
		a->z.x = (a->x - a->m->x0) * a->m->sc_w - a->m->offx_h;
		h.z.x = a->z.x;
		h.z.y = a->z.y;
		h.z_2.x = h.z.x * h.z.x;
		h.z_2.y = h.z.y * h.z.y;
		h.i = -1;
		while ((++h.i < MAX_ITERATIONS) && (h.z_2.x + h.z_2.y) < 4)
		{
			h.z.y = 2 * h.z.x * h.z.y + a->z.y;
			h.z.x = h.z_2.x - h.z_2.y + a->z.x;
			h.z_2.x = h.z.x * h.z.x;
			h.z_2.y = h.z.y * h.z.y;
		}
		if (h.i != MAX_ITERATIONS)
		{
			h.sqr_sum = sqrt(h.z_2.y + h.z_2.x);
			h.color = 255. * log2(2 + h.i - log2(log2(h.sqr_sum))) / log2((double)MAX_ITERATIONS);
			ft_set_pixel(add_ptr, a->x, a->y, ft_color(0, h.color, h.color));
		}
	}
}
