/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carpet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 16:05:40 by lsandor-          #+#    #+#             */
/*   Updated: 2019/03/02 18:04:56 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_init_info(t_f *m, t_fractol *f)
{
	m->sc_w = 2.0 / (0.5 * f->scale * W_WIDTH);
	m->sc_h = 1.2 / (0.5 * f->scale * W_HEIGHT);
	m->offx_h = f->offsetx / W_HEIGHT;
	m->offy_w = f->offsety / W_WIDTH;
	m->fract = f->fractal;
	m->x0 = f->x0;
	m->y0 = f->y0;
}

void	ft_burning_ship_fractol(t_fractol *f)
{
	t_f m;
	pthread_t threads[W_HEIGHT];
	t_args	args[W_HEIGHT];
	int i;

	ft_init_info(&m, f);
	i = -1;
	while (++i < W_HEIGHT)
	{
		args[i].y = i;
		args[i].x = -1;
		args[i].m = &m;
		args[i].add_ptr = f->add_ptr;
		args[i].i = -1;
		pthread_create(&threads[i], NULL, ft_print_fractal , (void*)&args[i]);
	}
	i = -1;
	while (++i < W_HEIGHT)
		pthread_join(threads[i], NULL);
}
static	void	ft_bs(t_j *tmp, char *add_ptr, int x, int y)
{
	t_j z;
	int i;
	unsigned char color;
	double xtemp;
	double sqr_sum;

	z.x = tmp->x;
	z.y = tmp->y;
	i = -1;
	while ((z.x * z.x + z.y * z.y < 20) && ++i < MAX_ITERATIONS)
	{
		xtemp = z.x * z.x - z.y * z.y + tmp->x;
		z.y = fabs(2 * z.x * z.y) + tmp->y;
		z.x = fabs(xtemp);
	}
	if (i != MAX_ITERATIONS)
	{
		sqr_sum = sqrt(z.x * z.x + z.y * z.y);
		color = 255. * log2(5 + i - log2(log2(sqr_sum))) / log2((double)MAX_ITERATIONS);
		ft_set_pixel(add_ptr, x, y, ft_color(0, color, color));
	}
}

void	*ft_print_fractal(void	*thread_args)
{
	t_args *a;

	a = (t_args*)thread_args;
	while (a->x++ < W_WIDTH)
	{
		a->z.x = (a->x - a->m->x0) * a->m->sc_w - a->m->offx_h;
		a->z.y = (a->y - a->m->y0) * a->m->sc_h + a->m->offy_w;
		a->m->fract == 3 ? ft_bs(&a->z, a->add_ptr, a->x, a->y) : 0;
	}
	return (NULL);
}
