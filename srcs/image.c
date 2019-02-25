/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:25:16 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/15 16:56:10 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_initialize_image(t_fdf *fdf)
{
	fdf->image->img_ptr = mlx_new_image(fdf->mlx_ptr, W_WIDTH, W_HEIGHT);
	fdf->image->add_ptr = mlx_get_data_addr(fdf->image->img_ptr,
			&fdf->image->bpp, &fdf->image->size_line, &fdf->image->endian);
	fdf->image->bpp /= 8;
	ft_print_map(*fdf);
}

void	ft_clear_image(t_img *image)
{
	ft_bzero(image->add_ptr, W_WIDTH * W_HEIGHT * image->bpp);
}

void	ft_set_pixel_to_image(t_fdf *fdf, int x, int y, int color)
{
	if (x < 0 || x > W_WIDTH || y < 0 || y > W_HEIGHT)
		return ;
	*(int *)(fdf->image->add_ptr + (x + y * W_WIDTH) * fdf->image->bpp) = color;
}
