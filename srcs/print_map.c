/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:55:20 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/15 17:08:32 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	ft_put_line_low(t_pixel p0, t_pixel p1, t_fdf *fdf)
{
	t_putline ln;

	ln.dx = p1.x - p0.x;
	ln.dy = p1.y - p0.y;
	ln.yi = 1;
	if (ln.dy < 0)
	{
		ln.yi = -1;
		ln.dy = -ln.dy;
	}
	ln.d = 2 * ln.dy - ln.dx;
	ln.y = p0.y;
	ln.x = p0.x;
	while (ln.x < p1.x)
	{
		ft_set_pixel_to_image(fdf, ln.x, ln.y, ft_get_color(ln, p0, p1));
		if (ln.d > 0)
		{
			ln.y += ln.yi;
			ln.d -= 2 * ln.dx;
		}
		ln.d += 2 * ln.dy;
		ln.x++;
	}
}

static	void	ft_put_line_high(t_pixel p0, t_pixel p1, t_fdf *fdf)
{
	t_putline	ln;

	ln.dx = p1.x - p0.x;
	ln.dy = p1.y - p0.y;
	ln.xi = 1;
	if (ln.dx < 0)
	{
		ln.xi = -1;
		ln.dx = -ln.dx;
	}
	ln.d = 2 * ln.dx - ln.dy;
	ln.x = p0.x;
	ln.y = p0.y;
	while (ln.y < p1.y)
	{
		ft_set_pixel_to_image(fdf, ln.x, ln.y, ft_get_color(ln, p0, p1));
		if (ln.d > 0)
		{
			ln.x += ln.xi;
			ln.d -= 2 * ln.dy;
		}
		ln.d += 2 * ln.dx;
		ln.y++;
	}
}

static void		ft_put_line(t_fdf *fdf)
{
	int tmpy;
	int tmpx;

	tmpy = fdf->second.y - fdf->first.y;
	if (tmpy < 0)
		tmpy = -tmpy;
	tmpx = fdf->second.x - fdf->first.x;
	if (tmpx < 0)
		tmpx = -tmpx;
	if (tmpy < tmpx)
		if (fdf->first.x > fdf->second.x)
			ft_put_line_low(fdf->second, fdf->first, fdf);
		else
			ft_put_line_low(fdf->first, fdf->second, fdf);
	else
	{
		if (fdf->first.y > fdf->second.y)
			ft_put_line_high(fdf->second, fdf->first, fdf);
		else
			ft_put_line_high(fdf->first, fdf->second, fdf);
	}
}

static void		ft_set_color(t_fdf *fdf, int color)
{
	double third;

	third = fdf->options->z0 / 3;
	if (fdf->first.z < 0)
		fdf->first.color = 0x0413e8;
	else if (fdf->first.z <= third)
		fdf->first.color = color;
	else if (fdf->first.z <= third * 2)
		fdf->first.color = 0x602B07;
	else if (fdf->first.z <= fdf->options->z0)
		fdf->first.color = 0xffffff;
	if (fdf->second.z < 0)
		fdf->second.color = 0x0413e8;
	else if (fdf->second.z <= third)
		fdf->second.color = color;
	else if (fdf->second.z <= third * 2)
		fdf->second.color = 0x602B07;
	else if (fdf->second.z <= fdf->options->z0)
		fdf->second.color = 0xFFFFFF;
	fdf->first.z /= fdf->decreaser;
	fdf->second.z /= fdf->decreaser;
}

void			ft_print_map(t_fdf fdf)
{
	ft_change_color(&fdf);
	ft_calculate_angles(&fdf);
	while (fdf.lines)
	{
		fdf.first = *((t_line *)fdf.lines->content)->b;
		fdf.second = *((t_line *)fdf.lines->content)->a;
		ft_set_color(&fdf, fdf.color);
		ft_rotate_dots(&fdf.first, fdf.res, &fdf);
		ft_rotate_dots(&fdf.second, fdf.res, &fdf);
		ft_put_line(&fdf);
		fdf.lines = fdf.lines->next;
	}
	while (fdf.drawn)
	{
		fdf.first = *((t_line *)fdf.drawn->content)->b;
		fdf.second = *((t_line *)fdf.drawn->content)->a;
		ft_put_line(&fdf);
		fdf.drawn = fdf.drawn->next;
	}
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, fdf.image->img_ptr, 0, 0);
	ft_put_string_to_window(fdf);
	mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 15, 6, 0xFFFFFF,
			"_____________________ USEFUL HOTKEYS _______________________");
	mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 15, 253, 0xFFFFFF,
			"____________________________________________________________");
}
