/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 22:29:34 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/28 23:55:13 by lsandor-         ###   ########.fr       */
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
}
static int ft_floor(int iter)
{
	return (iter / (MAX_ITERATIONS / 10));
}

static float	ft_pallete(int floor)
{
	int pallete[10] = {0x00FF00, 0x00000F, 0x0000FF, 0x0000F00, 0x000FFF, 0x00F000, 0x00FF00, 0x00FFF0, 0x0FFFF0, 0xFFFFFF};
		return (pallete[floor]);
}

static	float ft_lerp(float v0, float v1, float t)
{
	return (1 - t) * v0 + t + v1;
}

static	int	ft_color(int red, int green, int blue)
{
	int color;

	color = color >> 16 | red;
	color = color << 8 | green;
	color = color << 8 | blue;
	return (color);
}
/*void	*ft_calculate(void *a)
{
	t_mondel* m = (t_mondel *)a;
	m->iterations = -1;
	while (++m->iterations < MAX_ITERATIONS)
	{
		m->z_re2 = m->z_re * m->z_re;
		m->z_im2 = m->z_im * m->z_im;
		if (m->z_re2 + m->z_im2 > 4)
			break ;
		m->z_im = 2 * m->z_re * m->z_im + m->c_im;
		m->z_re = m->z_re2 - m->z_im2 + m->c_re;
	}
	return (NULL);
}*/

void	ft_mandelbrot_fractol(t_fractol *f)
{
	t_mondel m;
	pthread_t threads[NTHREADS];
	t_thread thread_args[NTHREADS];
	int i;
	int row;
	int tmp;

	row = W_HEIGHT / NTHREADS;
	tmp = 0;
	i = -1;
	ft_init_mondelbrot(&m, f);
	while (++i < NTHREADS)
	{
		thread_args[i].st = tmp;
		tmp += row;
		thread_ars[i].end = tmp;
		tmp += row;
		pthread_create(&threads[i], NULL, ft_calculate, (void*)&m);
	}
	i = -1;
	while (++i < NTHREADS)
	{
		pthread_join(threads[i], NULL);
	}
}
	
	
	
	
	
void	*ft_calculate(void *a)
{
	while (++m.y < W_HEIGHT)
	{
		m.c_im = m.max_im - ((m.y - f->y0) / f->scale + f->y0) * m.im_factor - f->offsety/W_WIDTH;
		m.x = -1;
		while (++m.x < W_WIDTH)
		{
			m.c_re = m.min_re + ((m.x - f->x0) / f->scale + f->x0) * m.re_factor - f->offsetx/W_HEIGHT;
			m.z_re = m.c_re;
			m.z_im = m.c_im;
			m.iterations = -1;	
		/*	while (++m.iterations < MAX_ITERATIONS)
			{
				m.z_re2 = m.z_re * m.z_re;
				m.z_im2 = m.z_im * m.z_im;
				if (m.z_re2 + m.z_im2 > 4)
					break ;
				m.z_im = 2 * m.z_re * m.z_im + m.c_im;
				m.z_re = m.z_re2 - m.z_im2 + m.c_re;
			}*/
			i = -1;
			while (i < NTHREADS)
			{
				thread_args[i] = i;
				pthread_join(threads[i], NULL);
			}
       		double z = sqrt(m.z_re2 + m.z_im2);
       		int brightness = 256. * log2(1.75 + m.iterations - log2(log2(z))) / log2((double)MAX_ITERATIONS);
        	ft_color(brightness, brightness, 255);
			/*if (m.iterations < MAX_ITERATIONS)
			{
				m.log_zn = log(m.z_re2 + m.z_im2) / 2;
				m.nu = log (m.log_zn / log(2)) / log(2);
				m.iterations = m.iterations - m.nu;
			}
			float color1 = ft_pallete(ft_floor(m.iterations));
			float color2 = ft_pallete(ft_floor(m.iterations) + 1);
			float color = ft_lerp(color1, color2, m.iterations - ((int)m.iterations));*/
			if (m.iterations != MAX_ITERATIONS)
				ft_set_pixel(f, m.x, m.y, ft_color(0, brightness, brightness));
		//	if (m.iterations != MAX_ITERATIONS)
		//		ft_choose_color(f, m.x, m.y, (double)m.iterations);
		}
	}
}
