/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 21:53:52 by lsandor-          #+#    #+#             */
/*   Updated: 2019/03/02 18:38:02 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_exit_error(int error)
{
	if (error == 1)
		ft_putstr("Error.\nUsage: \"./fractol fractal_name\"\nPossible fractal names:\nMandelbrot\n");
	exit(EXIT_FAILURE);
}

void	ft_exit_incorrect_name(void)
{
	ft_putstr("Error. No such fractal name.\nPossible fractal names:\nMandelbrot\n");
	exit(EXIT_FAILURE);
}

void	ft_check_fractol(t_fractol *f, char *str)
{
	f->fractal = -1;
	if (!ft_strcmp(str, "-M"))
		f->fractal = 1;
	else if (!ft_strcmp(str, "-J"))
		f->fractal = 2;
	else if (!ft_strcmp(str, "-BS"))
		f->fractal = 3;
	else if (f->fractal == -1)
		ft_exit_incorrect_name();
}
