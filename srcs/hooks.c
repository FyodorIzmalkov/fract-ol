/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 20:33:57 by lsandor-          #+#    #+#             */
/*   Updated: 2019/03/03 18:47:43 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(t_fractol *f)
{
	(void)f;
	exit(0);
}

int	ft_mouse_press(int button, int x, int y, t_fractol *f)
{
	if (x <= W_WIDTH && y <= W_HEIGHT)
	{
		ft_clear_image(f);
		printf("x: %d y: %d\n",x,y);
		if (button == 5)
		{
			f->scale *= 1.1;
			f->offsetx += (f->x0 - (double)x) / (f->scale * 3);
			f->offsety -= (f->y0 - (double)y) / (f->scale * 3);
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
		if (!f->c_button && f->fractal == 1)
		{
			ft_clear_image(f);
			f->curr_x = ((y - f->y0) / f->scale) / W_WIDTH;
			f->curr_y = ((x - f->x0) / f->scale) / W_HEIGHT;
		//	printf(" x:%f y:%f\n", f->curr_x, f->curr_y);
			ft_select_fractol(f);
		}
	}
	return (0);
}

int		ft_key_press(int keycode, t_fractol *f)
{
	ft_clear_image(f);
	if (keycode == 8)
	{
		if (!f->c_button)
			f->c_button = 1;
		else
			f->c_button = 0;
	}
	keycode == 123 ? f->x1 += 0.5 / f->scale : 0;
	keycode == 124 ? f->x1 -= 0.5 / f->scale : 0;
	keycode == 126 ? f->y1 += 0.5 / f->scale : 0;
	keycode == 125 ? f->y1 -= 0.5 / f->scale : 0;
	keycode == 83 ? f->set = 0 : 0;
	keycode == 84 ? f->set = 1 : 0;
	keycode == 85 ? f->set = 2 : 0;
	keycode == 86 ? f->set = 3 : 0;
	keycode == 87 ? f->set = 4 : 0;
	keycode == 88 ? f->set = 5 : 0;
	keycode == 89 ? f->set = 6 : 0;
	keycode == 91 ? f->set = 7 : 0;
	keycode == 92 ? f->set = 8 : 0;
	keycode == 53 ? exit(0) : 0;
	ft_select_fractol(f);
	return (0);
}

int		ft_key_release(int keycode, t_fractol *f)
{
	return (0);
}
