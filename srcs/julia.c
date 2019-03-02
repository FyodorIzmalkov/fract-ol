/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 20:38:05 by lsandor-          #+#    #+#             */
/*   Updated: 2019/03/02 15:21:55 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_j	ft_add(t_j a, t_j *b)
{
	t_j c;
	c.x = a.x + b->x;
	c.y = a.y + b->y;
	return (c);
}

static t_j ft_sqr(t_j *a)
{
	t_j c;
	c.x = a->x * a->x - a->y * a->y;
	c.y = 2 * a->x * a->y;
	return (c);
}

static double ft_mod(t_j a)
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

void	ft_julia_fractol(t_fractol *f)
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
}

void	*ft_julia(void *a)
{
	t_jul *j;

	j = (t_jul*)a;
	while (j->x++ < W_WIDTH)
	{
		j->z0.x = 1.5 * (j->x - j->x0 ) / (0.5 * j->scale * W_WIDTH) - j->offsetx/W_HEIGHT;
		j->z0.y = (j->y - j->y0) / (0.5 * j->scale * W_HEIGHT) + j->offsety/W_WIDTH;
		j->i = 0;
		while (j->i++ <= MAX_ITERATIONS)
		{
			j->z1 = ft_add(ft_sqr(&j->z0),&j->c);
			if ((j->z = ft_mod(j->z1)) > 4)
			{
				j->clr = 255. * log2(1.75 + j->i - log2(log2(j->z))) / log2((double)MAX_ITERATIONS);
				ft_set_pixel(j->add_ptr,j->x,j->y, ft_color(0, j->clr,j->clr));
				break;
			}
			j->z0 = j->z1;
		}
	}
	return (NULL);
}
