/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 22:13:41 by lsandor-          #+#    #+#             */
/*   Updated: 2019/03/03 21:53:39 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_initialize_fractol(t_fractol *f)
{
	f->x0 = (double)(W_WIDTH >> 1);
	f->y0 = (double)(W_HEIGHT >> 1);
	f->curr_x = -0.7;
	f->curr_y = 0.27;
	f->x1 = 0;
	f->y1 = 0;
	f->scale = 1;
	f->c_button = 0;
	f->set = 0;
	f->offsety = 0;
	f->offsetx = 0;
	f->iter = 100;
}

void	ft_initialize_image(t_fractol *f)
{
	f->img_ptr = mlx_new_image(f->mlx_ptr, W_WIDTH, W_HEIGHT);
	f->add_ptr = mlx_get_data_addr(f->img_ptr, &f->bpp, &f->size_line,
			&f->endian);
}

void	ft_select_fractol(t_fractol *f)
{
	if (f->fractal != -1)
		ft_multi_thread_fractals(f);
	mlx_put_image_to_window(f->mlx_ptr, f->mlx_win, f->img_ptr, 0, 0);
}
