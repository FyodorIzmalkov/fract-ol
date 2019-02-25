/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 18:36:26 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/15 17:06:12 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_apply_scale(t_pixel *pixel, t_fdf *fdf)
{
	double scaler;

	fdf->options->scale = fdf->col > fdf->row ? ((double)W_WIDTH / fdf->col)
			/ 2 : ((double)W_HEIGHT / fdf->row) / 2;
	scaler = fdf->options->scale * fdf->options->size;
	pixel->x *= scaler;
	pixel->y *= scaler;
	pixel->x += (W_WIDTH >> 1) + fdf->options->horiz;
	pixel->y += (W_HEIGHT >> 1) + fdf->options->vertic;
}

static	void	ft_apply_iso_scale(t_pixel *pixel, t_fdf *fdf)
{
	double scaler;

	scaler = fdf->options->iso_scale * fdf->options->size;
	pixel->x *= scaler;
	pixel->y *= scaler;
	pixel->x += (W_WIDTH >> 1) + fdf->options->horiz;
	pixel->y += (W_HEIGHT >> 1) + fdf->options->vertic;
}

static	void	ft_two_to_one_iso(t_pixel *pixel, t_fdf *fdf)
{
	double y;
	double x;

	y = pixel->y;
	x = pixel->x;
	pixel->x = (x - y) * 0.8943;
	pixel->y = ((x + y) * 0.4473) - pixel->z;
	ft_apply_iso_scale(pixel, fdf);
}

static	void	ft_chose_proection(t_pixel *pixel, t_fdf *fdf)
{
	double y;
	double x;

	if (fdf->options->proection == 1)
	{
		y = pixel->y;
		x = pixel->x;
		pixel->x = (x - y) * 0.8660;
		pixel->y = ((x + y) / 2) - pixel->z;
		ft_apply_iso_scale(pixel, fdf);
	}
	else if (fdf->options->proection == 2)
		ft_two_to_one_iso(pixel, fdf);
	else if (fdf->options->proection == 3)
	{
		pixel->x = pixel->x * fdf->options->x / (fdf->options->x - pixel->z);
		pixel->y = pixel->y * fdf->options->x / (fdf->options->x - pixel->z);
		ft_apply_iso_scale(pixel, fdf);
	}
	else
		ft_apply_scale(pixel, fdf);
}

void			ft_rotate_dots(t_pixel *pixel, t_calc res, t_fdf *fdf)
{
	t_pixel prev;

	pixel->x -= fdf->options->x0;
	pixel->y -= fdf->options->y0;
	if (fdf->options->altitude != 0 && pixel->z > fdf->options->min)
		pixel->z += fdf->options->altitude;
	if (fdf->options->min >= 0)
		pixel->z -= fdf->options->z0 / 2;
	prev.x = pixel->x;
	prev.z = pixel->z;
	pixel->x = prev.x * res.cosy + prev.z * res.siny;
	pixel->z = -prev.x * res.siny + prev.z * res.cosy;
	prev.y = pixel->y;
	prev.z = pixel->z;
	pixel->y = prev.y * res.cosx + prev.z * res.sinx;
	pixel->z = -prev.y * res.sinx + prev.z * res.cosx;
	prev.x = pixel->x;
	prev.y = pixel->y;
	pixel->x = prev.x * res.cosz - prev.y * res.sinz;
	pixel->y = prev.x * res.sinz + prev.y * res.cosz;
	ft_chose_proection(pixel, fdf);
}
