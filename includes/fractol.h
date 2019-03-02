/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:42:45 by lsandor-          #+#    #+#             */
/*   Updated: 2019/03/02 19:12:11 by lsandor-         ###   ########.fr       */
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
# define MAX_ITERATIONS 30
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
	unsigned char color;
	int i;
}				t_helper;
typedef struct s_f
{
	double sc_w;
	double sc_h;
	double offx_h;
	double offy_w;
	char fract;
	double x0;
	double y0;
}				t_f;

typedef struct s_args
{
	t_f *m;
	int y;
	int x;
	char *add_ptr;
	t_point z;
	int i;
	unsigned char clr;
}			t_args;

typedef struct s_jul
{
	int x;
	int y;
	t_point z0;
	t_point z1;
	t_point c;
	int i;
	char *add_ptr;
	double x0;
	double y0;
	double scale;
	double offsetx;
	double offsety;
	double z;
	unsigned char clr;
}				t_jul;

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
// mandelbrot.c
void	ft_mandelbrot_fractol(t_fractol *f);
void	ft_mandelbrot(t_args *a, char *add_ptr);
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
void	ft_julia_fractol(t_fractol *f);
void	*ft_julia(void *a);
void	ft_julia1(void *a);
void	ft_julia2(void *a);
//carpet
void	ft_multi_thread_fractals(t_fractol *f);
void	*ft_print_fractal(void *thread_args);
#endif
