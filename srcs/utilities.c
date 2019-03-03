/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 21:53:52 by lsandor-          #+#    #+#             */
/*   Updated: 2019/03/03 22:16:24 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				ft_exit_error(int error)
{
	if (error == 1)
		ft_putstr("Error. Usage: ./fractol -fractal_flag\n");
	exit(EXIT_FAILURE);
}

void			ft_exit_incorrect_name(void)
{
	ft_putstr("Error. No such fractal name.\nPossible fractal names:\n");
	ft_putstr("-M Mandelbrot set\n-J Julia set\n-BS Burning ship\n");
	ft_putstr("-C Sierpinski carpet\n-R1 -R2 -R3 -R4 for random fractals\n");
	exit(EXIT_FAILURE);
}

void			ft_check_fractol(t_fractol *f, char *str)
{
	f->fractal = -1;
	if (!ft_strcmp(str, "-M"))
		f->fractal = 0;
	else if (!ft_strcmp(str, "-J"))
		f->fractal = 1;
	else if (!ft_strcmp(str, "-BS"))
		f->fractal = 2;
	else if (!ft_strcmp(str, "-C"))
		f->fractal = 3;
	else if (!ft_strcmp(str, "-R1"))
		f->fractal = 4;
	else if (!ft_strcmp(str, "-R2"))
		f->fractal = 5;
	else if (!ft_strcmp(str, "-R3"))
		f->fractal = 6;
	else if (!ft_strcmp(str, "-R4"))
		f->fractal = 7;
	else if (f->fractal == -1)
		ft_exit_incorrect_name();
}

static	void	ft_put_str2(t_fractol *f)
{
	mlx_string_put(f->mlx_ptr, f->mlx_win, 1005, 180, 0xFFFFFF,
			"| R - to reset setting to defaults             |");
	mlx_string_put(f->mlx_ptr, f->mlx_win, 1005, 195, 0xFFFFFF,
			"o----------------------------------------------o");
}

void			ft_put_string_to_window(t_fractol *f)
{
	char *num;

	num = ft_itoa(f->iter);
	mlx_string_put(f->mlx_ptr, f->mlx_win, 1005, 5, 0xFFFFFF,
			"o----------------------------------------------o");
	mlx_string_put(f->mlx_ptr, f->mlx_win, 1005, 20, 0xFFFFFF,
			"| + / - to change fractals                     |");
	mlx_string_put(f->mlx_ptr, f->mlx_win, 1005, 40, 0xFFFFFF,
			"| NUM 1 to 9 - to change color sets            |");
	mlx_string_put(f->mlx_ptr, f->mlx_win, 1005, 60, 0xFFFFFF,
			"| Scrool with mouse to zoom in and out         |");
	mlx_string_put(f->mlx_ptr, f->mlx_win, 1005, 80, 0xFFFFFF,
			"| C - to stop Julia's set changing             |");
	mlx_string_put(f->mlx_ptr, f->mlx_win, 1005, 100, 0xFFFFFF,
			"| ARROWS - to move the image                   |");
	mlx_string_put(f->mlx_ptr, f->mlx_win, 1005, 120, 0xFFFFFF,
			"| 1 - to increase max iterations               |");
	mlx_string_put(f->mlx_ptr, f->mlx_win, 1005, 140, 0xFFFFFF,
			"| 2 - to decrease max iterations               |");
	mlx_string_put(f->mlx_ptr, f->mlx_win, 1005, 160, 0xFFFFFF,
			"| Current iterations number:                   |");
	mlx_string_put(f->mlx_ptr, f->mlx_win, 1310, 160, 0xFFFFFF, num);
	ft_put_str2(f);
}
