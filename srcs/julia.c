/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 20:38:05 by lsandor-          #+#    #+#             */
/*   Updated: 2019/03/01 23:47:46 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_j	ft_add(t_j a, t_j b)
{
	t_j c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}

static t_j ft_sqr(t_j a)
{
	t_j c;
	c.x = a.x * a.x - a.y * a.y;
	c.y = 2 * a.x * a.y;
	return (c);
}

static double ft_mod(t_j a)
{
	return (sqrt(a.x *a.x + a.y * a.y));
}

static	t_j ft_map_point(int x, int y, t_jul *f)
{
	t_j c;

	c.x = 1.5 * (x - f->x0 ) / (0.5 * f->scale * W_WIDTH) - f->offsetx/W_HEIGHT;
	c.y = (y - f->y0) / (0.5 * f->scale * W_HEIGHT) + f->offsety/W_WIDTH;
	return (c);
}
static void	ft_julia_init(t_jul *j, int i, t_fractol *f)
{
	j->x = 0;
	j->y = i;
	j->c.x = -0.7;
	j->c.y = 0.27;
	j->add_ptr = f->add_ptr;
	j->i = 1;
	j->x0 = f->x0;
	j->y0 = f->y0;
	j->scale = f->scale;
	j->offsetx = f->offsetx;
	j->offsety = f->offsety;
}

void	ft_julia_fractol(t_fractol *f)
{
	t_jul t_arg;

//	ft_julia_init(&t_arg,0,f);
//	ft_julia1(&t_arg);
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

void	ft_julia2(void *a)
{
	int x,y,i;
	t_j z0;
	t_j z1;
	t_jul *j;
	t_j c;
	c.x = -0.7;
	c.y = 0.27;
	j = (t_jul*)a;
	y = 0;
	while (y < W_HEIGHT)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			z0 = ft_map_point(x, y, j);
			i = 1;
			while (i++ <= MAX_ITERATIONS)
			{
				z1 = ft_add(ft_sqr(z0),c);
				printf("x:%f y:%f\n",j->z1.x,j->z1.y);
				if (ft_mod(z1) > 2)
				{
					ft_set_pixel(j->add_ptr,x,y, 0x00FFFFFF);
					break;
				}
				z0 = z1;
			}
			if (i > MAX_ITERATIONS)
				ft_set_pixel(j->add_ptr,x,y,0);
			x++;
		}
		y++;
	}
}

void	ft_julia1(void *a)
{
	t_jul *j;

	j = (t_jul*)a;
	while (j->y < W_HEIGHT)
	{
		while (j->x < W_WIDTH)
		{
			j->z0 = ft_map_point(j->x, j->y, j);
			j->i = 1;
			printf("j->i:%d\n",j->i);
			while (j->i++ <= MAX_ITERATIONS)
			{
				j->z1 = ft_add(ft_sqr(j->z0),j->c);
				printf("x:%f y:%f\n",j->z1.x,j->z1.y);
				if (ft_mod(j->z1) > 2)
				{
					ft_set_pixel(j->add_ptr,j->x,j->y, 0x00FFFFFF);
					break;
				}
				j->z0 = j->z1;
			}
			if (j->i > MAX_ITERATIONS)
				ft_set_pixel(j->add_ptr,j->x,j->y,0);
			j->x++;
		}
		j->y++;
	}
}

void	*ft_julia(void *a)
{
	t_jul *j;

	j = (t_jul*)a;
	while (j->x++ < W_WIDTH)
	{
		j->z0 = ft_map_point(j->x, j->y, j);
		j->i = 0;
		while (j->i++ <= MAX_ITERATIONS)
		{
			j->z1 = ft_add(ft_sqr(j->z0),j->c);
			if (ft_mod(j->z1) > 4)
			{
				ft_set_pixel(j->add_ptr,j->x,j->y, 0x00FFFFFF);
				break;
			}
			j->z0 = j->z1;
		}
		if (j->i > MAX_ITERATIONS)
			ft_set_pixel(j->add_ptr,j->x,j->y,0);
	}
	return (NULL);
}
