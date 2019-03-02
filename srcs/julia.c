/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 20:38:05 by lsandor-          #+#    #+#             */
/*   Updated: 2019/03/02 20:03:01 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_point ft_add(t_point a, t_point *b)
{
	t_point c;
	c.x = a.x + b->x;
	c.y = a.y + b->y;
	return (c);
}

static t_point ft_sqr(t_point *a)
{
	t_point c;
	c.x = a->x * a->x - a->y * a->y;
	c.y = 2 * a->x * a->y;
	return (c);
}

static double ft_mod(t_point a)
{
	return (sqrt(a.x *a.x + a.y * a.y));
}

static void	ft_julia_init(t_jul *j, int i, t_fractol *f)
{
	j->x = 0;
	j->y = i;
	j->c.x = f->curr_x;
	j->c.y = f->curr_y;
	j->add_ptr = f->add_ptr;
	j->i = 1;
	j->x0 = f->x0;
	j->y0 = f->y0;
	j->scale = f->scale;
	j->offsetx = f->offsetx;
	j->offsety = f->offsety;
	j->z = 0;
	j->clr = 0;
}

/*void	ft_julia_fractol(t_fractol *f)
{
	t_jul t_arg;

	pthread_t threads[W_HEIGHT];
	t_jul t_args[W_HEIGHT];
	int i = -1;

	while (++i < W_HEIGHT)
	{
		ft_julia_init(&t_args[i],i,f);
		pthread_create(&threads[i], NULL, ft_julia, (void*)&t_args[i]);
	}
	i = -1;
	while (++i < W_HEIGHT)
		pthread_join(threads[i], NULL);
}*/

void	ft_julia(t_args *a, char *add_ptr)
{
	t_helper h;

	while (++a->x < W_WIDTH)
	{
		a->z.x = (a->x - a->m->x0) * a->m->sc_w - a->m->offx_h;
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
			ft_set_pixel(add_ptr, a->x, a->y, ft_color(0, h.color,h.color));
		}
	}
}
