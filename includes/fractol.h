/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:42:45 by lsandor-          #+#    #+#             */
/*   Updated: 2019/03/01 19:49:50 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include <errno.h>
# include <mlx.h>
# include <fcntl.h>
# include "libft.h"
# include <stdio.h>
# include <pthread.h>
# define W_WIDTH 900
# define W_HEIGHT 900
# define MAX_ITERATIONS 30
# define NTHREADS W_HEIGHT * 2

typedef struct s_mondel
{
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	re_factor;
	double	im_factor;
	double	c_re;
	double	c_im;
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;
	char	is_inside;
	int	 y;
	int x;
	double iterations;
	float log_zn;
	float nu;
	double x0;
	double y0;
	double offsetx;
	double offsety;
	double scale;
}				t_mondel;

typedef struct s_fractol
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img_ptr;
	char	*add_ptr;
	int		bpp;
	int		size_line;
	int		endian;
	char	fractal;
	double x0;
	double y0;
	double offsetx;
	double offsety;
	double scale;
}		t_fractol;

typedef struct s_thread
{
	t_mondel mon;
	int st;
	int end;
	int stx;
	int endx;
	char *add_ptr;
}				t_thread;
// utilities.c
int	ft_exit_error(int error);
void	ft_exit_incorrect_name(void);
void	ft_check_fractol(t_fractol *f, char *str);
// initialize.c
void	ft_select_fractol(t_fractol *f);
// fractols.c
void	ft_mandelbrot_fractol(t_fractol *f);
void	*ft_calculate(void *m);
// image.c
void	ft_initialize_image(t_fractol *f);
void	ft_set_pixel(char *add_ptr, int x, int y, int color);
void	ft_clear_image(t_fractol *f);
//color.c
void	ft_choose_color(char *add_ptr, int x, int y, double iter);
//hooks.c
int	ft_mouse_press(int button, int x, int y, t_fractol *f);
int				ft_mouse_move(int x, int y, t_fractol *f);
#endif
