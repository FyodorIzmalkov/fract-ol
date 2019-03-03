/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:42:45 by lsandor-          #+#    #+#             */
/*   Updated: 2019/03/03 14:50:36 by lsandor-         ###   ########.fr       */
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
# define W_WIDTH 1000
# define W_HEIGHT 800
# define MAX_ITERATIONS 100
# define NTHREADS W_HEIGHT * 2

typedef struct s_point
{
	double x;
	double y;
}				t_point;

typedef struct s_helper
{
	t_point z;
	t_point z_2;
	double sqr_sum;
	double xtemp;
	unsigned char color;
	int i;
	int x;
}				t_helper;

typedef struct s_options
{
	double sc_w;
	double sc_h;
	double offx_h;
	double offy_w;
	char fract;
	double x0;
	double y0;
	double	curx;
	double cury;
	double *scale;
	unsigned char clr;
	char *add_ptr;
}				t_options;

typedef struct s_args
{
	t_options *m;
	int y;
	t_point z;
	int i;
}			t_args;

typedef struct s_fractol
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img_ptr;
	char	*add_ptr;
	char	c_button;
	int		bpp;
	int		size_line;
	int		endian;
	char	fractal;
	double x0;
	double y0;
	double offsetx;
	double offsety;
	double scale;
	double curr_x;
	double curr_y;
}		t_fractol;

// utilities.c
int	ft_exit_error(int error);
void	ft_exit_incorrect_name(void);
void	ft_check_fractol(t_fractol *f, char *str);
// initialize.c
void	ft_select_fractol(t_fractol *f);
// mandelbrot.c
void	ft_mandelbrot(t_args *a);
// image.c
void	ft_initialize_image(t_fractol *f);
void	ft_set_pixel(char *add_ptr, int x, int y, int color);
void	ft_clear_image(t_fractol *f);
//color.c
void	ft_choose_color(char *add_ptr, int x, int y, double iter);
int		ft_color(unsigned char red, unsigned char green, unsigned char blue);
//hooks.c
int	ft_mouse_press(int button, int x, int y, t_fractol *f);
int				ft_mouse_move(int x, int y, t_fractol *f);
int	ft_key_press(int keycode, t_fractol *f);
int	ft_key_release(int keycode, t_fractol *f);
//julia.c
void	ft_julia(t_args *a);
//print_fractals.c
void	ft_multi_thread_fractals(t_fractol *f);
void	*ft_print_fractal(void *thread_args);
// carpet.c
void	ft_carpet(t_args *a);
//random_fractals
void	ft_random_fractal_two(t_args *a);
void	ft_random_fractal_three(t_args *a);
void	ft_random_fractal_four(t_args *a);
void	ft_random_fractal_five(t_args *a);
#endif
