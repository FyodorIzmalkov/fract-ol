/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 22:29:34 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/25 23:57:47 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	ft_init_mondelbrot(t_mondel *m)
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
}

void	ft_mandelbrot_fractol(t_fractol *f)
{
	t_mondel m;

	ft_init_mondelbrot(&m);

	while (++m.y < W_HEIGHT)
	{
		m.c_im = m.max_im - m.y * m.im_factor;
		m.x = -1;
		while (++m.x < W_WIDTH)
		{
			m.c_re = m.min_re + m.x * m.re_factor;
			m.z_re = m.c_re;
			m.z_im = m.c_im;
			m.is_inside = 1;
			m.iterations = -1;
			while (++m.iterations < MAX_ITERATIONS)
			{
				m.z_re2 = m.z_re * m.z_re;
				m.z_im2 = m.z_im * m.z_im;
				if (m.z_re2 + m.z_im2 > 4)
				{
					m.is_inside = 0;
					break ;
				}
				m.z_im = 2 * m.z_re * m.z_im + m.c_im;
				m.z_re = m.z_re2 - m.z_im2 + m.c_re;
			}
			if (m.is_inside)
				ft_choose_color(f, m.x, m.y, m.iterations);
		}
	}
}
