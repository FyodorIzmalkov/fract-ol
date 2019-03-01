/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 23:16:33 by lsandor-          #+#    #+#             */
/*   Updated: 2019/03/02 00:12:00 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_initialize_image(t_fractol *f)
{
	f->x0 = (double)(W_WIDTH >> 1);
	f->y0 = (double)(W_HEIGHT >> 1);
	f->curr_x = -0.7;
	f->curr_y = 0.27;
	f->scale = 1;
	f->c_button = 0;
	f->img_ptr = mlx_new_image(f->mlx_ptr, W_WIDTH, W_HEIGHT);
	f->add_ptr = mlx_get_data_addr(f->img_ptr, &f->bpp, &f->size_line,
			&f->endian);
	f->bpp /= 8;
}

void	ft_set_pixel(char *add_ptr, int x, int y, int color)
{
	static int i = 0;
	i++;
//	printf("i = %d x = %d y = %d \n",i,x,y);
	*(int *)(add_ptr + (x + y * W_WIDTH) * 4) = color;
}

void	ft_clear_image(t_fractol *f)
{
	ft_bzero(f->add_ptr, W_WIDTH * W_HEIGHT * 4);
}
