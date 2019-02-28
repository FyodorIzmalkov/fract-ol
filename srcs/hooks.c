/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 20:33:57 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/28 18:47:35 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mouse_press(int button, int x, int y, t_fractol *f)
{
	if (x <= W_WIDTH && y <= W_HEIGHT)
	{
		ft_clear_image(f);
		printf("x: %d y: %d\n",x,y);
		if (button == 5)
		{
			f->scale *= 1.1;
			f->x0 += 10;
		//	f->offsetx = x / f->scale;
		//	f->offsety = y/ f->scale;
		}
		button == 4 ? f->scale *= 0.9 : 0;
		printf("f->scale=%f\n",f->scale);
		ft_select_fractol(f);
	}
	return (0);
}

int		ft_mouse_move(int x, int y, t_fractol *f)
{
	if ((x >= 0 && x<= W_WIDTH) && y >= 0 && y <= W_HEIGHT)
	{
		//ft_clear_image(f);
	//	f->x0 = x;
	//	f->y0 = y;
		//ft_select_fractol(f);
	}
	return (0);
}
