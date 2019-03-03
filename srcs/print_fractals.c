/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fractals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 16:05:40 by lsandor-          #+#    #+#             */
/*   Updated: 2019/03/03 14:50:51 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_init_info(t_options *m, t_fractol *f)
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
}

void	ft_multi_thread_fractals(t_fractol *f)
{
	t_options m;
	pthread_t threads[W_HEIGHT];
	t_args	args[W_HEIGHT];
	int i;

	ft_init_info(&m, f);
	i = -1;
	while (++i < W_HEIGHT)
	{
		args[i].y = i;
		args[i].m = &m;
		//args[i].add_ptr = f->add_ptr;
		args[i].i = -1;
		pthread_create(&threads[i], NULL, ft_print_fractal , (void*)&args[i]);
	}
	i = -1;
	while (++i < W_HEIGHT)
		pthread_join(threads[i], NULL);
}
static	void	ft_burning_ship(t_args *a)
{
	t_helper h;

	h.x = -1;
	while (++h.x < W_WIDTH)
	{
		a->z.x = (h.x - a->m->x0) * a->m->sc_w - a->m->offx_h;
		h.z.x = a->z.x;
		h.z.y = a->z.y;
		h.z_2.x = h.z.x * h.z.x;
		h.z_2.y = h.z.y * h.z.y;
		h.i = -1;
		while ((++h.i < MAX_ITERATIONS) && (h.z_2.x + h.z_2.y) < 20)
		{
			h.xtemp = h.z_2.x - h.z_2.y + a->z.x;
			h.z.y = fabs(2 * h.z.x * h.z.y) + a->z.y;
			h.z.x = fabs(h.xtemp);
			h.z_2.x = h.z.x * h.z.x;
			h.z_2.y = h.z.y * h.z.y;
		}
		if (h.i != MAX_ITERATIONS)
		{
			h.sqr_sum = sqrt(h.z_2.x + h.z_2.y);
			h.color = 255. * log2(5 + h.i - log2(log2(h.sqr_sum))) / log2((double)MAX_ITERATIONS);
			ft_set_pixel(a->m->add_ptr, h.x, a->y, ft_color(0, h.color, h.color));
		}
	}
}

void	*ft_print_fractal(void	*thread_args)
{
	t_args *a;

	a = (t_args*)thread_args;
	a->z.y = (a->y - a->m->y0) * a->m->sc_h + a->m->offy_w;
	if (a->m->fract == 1)
		ft_mandelbrot(a);
	else if (a->m->fract == 2)
		ft_julia(a);
	else if (a->m->fract == 3)
		ft_burning_ship(a);
	else if (a->m->fract == 4)
		ft_carpet(a);
	else if (a->m->fract == 5)
		ft_random_fractal_two(a);
	else if (a->m->fract == 6)
		ft_random_fractal_three(a);
	else if (a->m->fract == 7)
		ft_random_fractal_four(a);
	else if (a->m->fract == 8)
		ft_random_fractal_five(a);
	return (NULL);
}
