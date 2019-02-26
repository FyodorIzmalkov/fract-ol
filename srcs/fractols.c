/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 22:29:34 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/26 18:43:48 by lsandor-         ###   ########.fr       */
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
static int ft_floor(int iter)
{
	if (iter <= MAX_ITERATIONS / 3)
		return (1);
	else if (iter <= MAX_ITERATIONS * 2 / 3)
		return (2);
	else
		return (3);
}

static float	ft_pallete(int floor)
{
	if (floor == 1)
		return (0x000000);
	else if (floor == 2)
		return (0xFF0000);
	else
		return (0xFFFFFF);
}

static	float ft_lerp(float v0, float v1, float t)
{
	return (1 - t) * v0 + t + v1;
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
					break ;
				m.z_im = 2 * m.z_re * m.z_im + m.c_im;
				m.z_re = m.z_re2 - m.z_im2 + m.c_re;
			}
/*			if (m.iterations < MAX_ITERATIONS)
			{
				m.log_zn = log(m.z_re2 + m.z_im2) / 2;
				m.nu = log (m.log_zn / log(2)) / log(2);
				m.iterations = m.iterations - m.nu;
			}
			float color1 = ft_pallete(ft_floor(m.iterations));
			float color2 = ft_pallete(ft_floor(m.iterations) + 1);
			float color = ft_lerp(color1, color2, m.iterations % 1.0f);
			ft_set_pixel(f, m.x, m.y, color);*/
			if (m.iterations != MAX_ITERATIONS)
				ft_choose_color(f, m.x, m.y, (double)m.iterations);
		}
	}
}
