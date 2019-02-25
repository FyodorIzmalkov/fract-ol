/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 23:16:33 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/25 23:32:23 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_initialize_image(t_fractol *f)
{
	f->img_ptr = mlx_new_image(f->mlx_ptr, W_WIDTH, W_HEIGHT);
	f->add_ptr = mlx_get_data_addr(f->img_ptr, &f->bpp, &f->size_line,
			&f->endian);
	f->bpp /= 8;
}

void	ft_set_pixel(t_fractol *f, int x, int y, int color)
{
	*(int *)(f->add_ptr + (x + y * W_WIDTH) * f->bpp) = color;
}
