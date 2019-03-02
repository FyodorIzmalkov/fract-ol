/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 22:29:34 by lsandor-          #+#    #+#             */
/*   Updated: 2019/03/02 15:58:14 by lsandor-         ###   ########.fr       */
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

void	ft_mandelbrot_fractol(t_fractol *f)
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
}
	
	
	
	
	
void	*ft_calculate(void *a)
{
	t_thread *m;

	m = (t_thread*)a;
	while (m->st <= m->end)
	{
		m->mon.c_im = m->mon.max_im - ((m->st - m->mon.y0) / m->mon.scale 
				+ m->mon.y0) * m->mon.im_factor - m->mon.offsety/W_WIDTH;
		while (m->stx < m->endx)
		{
			m->mon.c_re = m->mon.min_re + ((m->stx - m->mon.x0) / m->mon.scale 
					+ m->mon.x0) * m->mon.re_factor - m->mon.offsetx/W_HEIGHT;
			m->mon.z_re = m->mon.c_re;
			m->mon.z_im = m->mon.c_im;
			m->mon.iterations = -1;	
			while (++m->mon.iterations < MAX_ITERATIONS)
			{
				m->mon.z_re2 = m->mon.z_re * m->mon.z_re;
				m->mon.z_im2 = m->mon.z_im * m->mon.z_im;
				if (m->mon.z_re2 + m->mon.z_im2 > 12)
					break ;
				m->mon.z_im = 2 * m->mon.z_re * m->mon.z_im + m->mon.c_im;
				m->mon.z_re = m->mon.z_re2 - m->mon.z_im2 + m->mon.c_re;
			}
       		double z = sqrt(m->mon.z_re2 + m->mon.z_im2);
       		unsigned char brightness = 255. * log2(2 + m->mon.iterations - log2(log2(z))) / log2((double)MAX_ITERATIONS);
			if (m->mon.iterations != MAX_ITERATIONS)
				ft_set_pixel(m->add_ptr, m->stx, m->st, ft_color(0, brightness, brightness));
		m->stx++;
		}
	m->st++;
	}
	return (NULL);
}
