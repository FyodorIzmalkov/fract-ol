/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 22:13:41 by lsandor-          #+#    #+#             */
/*   Updated: 2019/03/02 18:37:00 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_select_fractol(t_fractol *f)
{
	if (f->fractal == 1)
		ft_multi_thread_fractals(f);
	if (f->fractal == 2)
		ft_julia_fractol(f);
	if (f->fractal == 3)
		ft_multi_thread_fractals(f);
	mlx_put_image_to_window(f->mlx_ptr, f->mlx_win, f->img_ptr, 0, 0);
}
