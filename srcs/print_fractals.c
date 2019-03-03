/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fractals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 16:05:40 by lsandor-          #+#    #+#             */
/*   Updated: 2019/03/03 19:05:57 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	ft_burning_ship(t_args *a)
{
	t_helper h;

	h.x = -1;
	while (++h.x < W_WIDTH)
	{
		h.zx = (h.x - a->m->x0) * a->m->sc_w - a->m->offx_h - a->m->x1;
		h.z.x = h.zx;
		h.z.y = a->zy;
		h.z_2.x = h.z.x * h.z.x;
		h.z_2.y = h.z.y * h.z.y;
		h.i = -1;
		while ((++h.i < MAX_ITERATIONS) && (h.z_2.x + h.z_2.y) < 20)
		{
			h.xtemp = h.z_2.x - h.z_2.y + h.zx;
			h.z.y = fabs(2 * h.z.x * h.z.y) + a->zy;
			h.z.x = fabs(h.xtemp);
			h.z_2.x = h.z.x * h.z.x;
			h.z_2.y = h.z.y * h.z.y;
		}
		if (h.i != MAX_ITERATIONS)
			*(int *)(a->m->add_ptr + (h.x + a->y * W_WIDTH) * 4) = ft_clr(&h, a->m->set);
	}
}

static void	ft_init_options(t_options *m, t_fractol *f)
{
	m->sc_w = 2.0 / (0.5 * f->scale * W_WIDTH);
	m->sc_h = 1.2 / (0.5 * f->scale * W_HEIGHT);
	m->offx_h = f->offsetx / W_HEIGHT;
	m->offy_w = f->offsety / W_WIDTH;
	m->fract = f->fractal;
	m->x0 = f->x0;
	m->y0 = f->y0;
	m->curx = f->curr_x;
	m->cury = f->curr_y;
	m->scale = &f->scale;
	m->add_ptr = f->add_ptr;
	m->x1 = f->x1;
	m->y1 = f->y1;
	m->set = f->set;
}

void	ft_multi_thread_fractals(t_fractol *f)
{
	t_options m;
	pthread_t threads[W_HEIGHT];
	t_args	args[W_HEIGHT];
	int i;

	ft_init_options(&m, f);
	i = -1;
	while (++i < W_HEIGHT)
	{
		args[i].y = i;
		args[i].m = &m;
		pthread_create(&threads[i], NULL, ft_print_fractal, (void*)&args[i]);
	}
	i = -1;
	while (++i < W_HEIGHT)
		pthread_join(threads[i], NULL);
}

void	*ft_print_fractal(void	*thread_args)
{
	t_args *a;
	static unsigned flag = 0;
	static void	(*p[9]) (t_args *a);

	a = (t_args*)thread_args;
	if (flag == 0)
	{
		p[0] = ft_mandelbrot;
		p[1] = ft_julia;
		p[2] = ft_burning_ship;
		p[3] = ft_carpet;
		p[4] = ft_random_fractal_two;
		p[5] = ft_random_fractal_three;
		p[6] = ft_random_fractal_four;
		p[7] = ft_random_fractal_five;
		flag = 1;
	}
	a->zy = (a->y - a->m->y0) * a->m->sc_h + a->m->offy_w - a->m->y1;
	p[a->m->fract](a);
	return (NULL);
}
