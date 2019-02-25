/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 20:49:21 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/15 17:03:32 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_display_error(int condition, int i)
{
	if (condition)
	{
		if (i == 1)
			ft_putendl("Error. Usage: ./fdf filename");
		else if (i == 2)
			ft_putendl("Error. Invalid file name.");
		else if (i == 3)
			ft_putendl("Error. Malloc allocation failed.");
		else if (i == 4)
			ft_putendl("Error. Map is invalid.");
		exit(EXIT_FAILURE);
	}
}

void	ft_free_args(char ***args, int i)
{
	while (i--)
	{
		free(args[0][i]);
		args[0][i] = NULL;
	}
	free(args[0]);
	args[0] = NULL;
}

void	ft_calculate_angles(t_fdf *fdf)
{
	fdf->res.sinx = sin(fdf->angle.x);
	fdf->res.cosx = cos(fdf->angle.x);
	fdf->res.siny = sin(fdf->angle.y);
	fdf->res.cosy = cos(fdf->angle.y);
	fdf->res.sinz = sin(fdf->angle.z);
	fdf->res.cosz = cos(fdf->angle.z);
}

int		ft_red_cross(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void	ft_draw_with_rmb(int x, int y, t_fdf *fdf)
{
	t_line	dat;
	t_pixel	f;
	t_pixel	s;

	if (fdf->mouse.draw_button == 0)
	{
		fdf->mouse.x1 = x;
		fdf->mouse.y1 = y;
		fdf->mouse.draw_button = 1;
		return ;
	}
	fdf->mouse.draw_button = 0;
	f.x = fdf->mouse.x1;
	f.y = fdf->mouse.y1;
	s.x = x;
	s.y = y;
	dat.a = &f;
	dat.b = &s;
	ft_display_error(!(fdf->drawn = ft_lstnew(&dat, sizeof(t_line))), 3);
	ft_print_map(*fdf);
	free(fdf->drawn);
	fdf->drawn = NULL;
}
