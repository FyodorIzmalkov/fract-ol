/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:27:19 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/15 16:55:41 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_decreaser(t_fdf *fdf)
{
	if (fdf->options->max > 10 && fdf->options->max < 100)
		fdf->decreaser = 2;
	else if (fdf->options->max >= 100 && fdf->options->max < 1000)
		fdf->decreaser = 10;
	else if (fdf->options->max >= 1000 && fdf->options->max < 10000)
		fdf->decreaser = 50;
}

void	ft_change_color(t_fdf *fdf)
{
	if (fdf->color_changer == 1)
		fdf->color = 0x077F11;
	else if (fdf->color_changer == 2)
		fdf->color = 0xd80a37;
	else if (fdf->color_changer == 3)
		fdf->color = 0xa00c96;
	else if (fdf->color_changer == 4)
		fdf->color = 0x5f0cb7;
	else if (fdf->color_changer == 5)
		fdf->color = 0x06cfe5;
	else if (fdf->color_changer == 6)
		fdf->color = 0x05e59e;
	else if (fdf->color_changer == 7)
		fdf->color = 0x0ad340;
	else if (fdf->color_changer == 8)
		fdf->color = 0xa5e209;
	else if (fdf->color_changer == 9)
		fdf->color = 0xddcc0b;
	else if (fdf->color_changer == 10)
		fdf->color = 0xd16b0c;
}

void	ft_put_string_to_window(t_fdf fdf)
{
	mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 10, 25, 0xFFFFFF,
			"| W / S - to rotate X axis                                  |");
	mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 10, 45, 0xFFFFFF,
			"| A / D - to rotate Y axis                                  |");
	mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 10, 65, 0xFFFFFF,
			"| Q / E - to rotate Z axis                                  |");
	mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 10, 85, 0xFFFFFF,
			"| ARROWS - to move the image                                |");
	mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 10, 105, 0xFFFFFF,
			"| < and > - to change Z multiplier                          |");
	mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 10, 125, 0xFFFFFF,
			"| NUM's '+' and '-' to change Z value                       |");
	mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 10, 145, 0xFFFFFF,
			"| TAB - to change colors                                    |");
	mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 10, 165, 0xFFFFFF,
			"| R / F or Mouse scroll to change size                      |");
	mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 10, 185, 0xFFFFFF,
			"| 1 2 3 4 - to select projection                            |");
	mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 10, 205, 0xFFFFFF,
			"| You can rotate the image with mouse left button pressed   |");
	mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 10, 225, 0xFFFFFF,
			"| Draw a line with 2 mouse right clicks                     |");
	mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 10, 245, 0xFFFFFF,
			"| ECS - to close the FDF                                    |");
}
