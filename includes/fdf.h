/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:42:45 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/15 17:20:07 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <math.h>
# include <errno.h>
# include <mlx.h>
# include <fcntl.h>
# include "libft.h"
# define W_WIDTH 2560
# define W_HEIGHT 1300

typedef struct	s_putline
{
	int	dx;
	int	dy;
	int	xi;
	int	yi;
	int	d;
	int	x;
	int	y;
}				t_putline;

typedef struct	s_alg
{
	int dx;
	int dy;
	int p;
	int x;
	int y;
}				t_alg;

typedef struct	s_calc
{
	double sinx;
	double cosx;
	double siny;
	double cosy;
	double sinz;
	double cosz;
}				t_calc;

typedef struct	s_img
{
	void	*img_ptr;
	char	*add_ptr;
	int		bpp;
	int		size_line;
	int		endian;
}				t_img;

typedef struct	s_pixel
{
	double	x;
	double	y;
	double	z;
	int		color;
}				t_pixel;

typedef struct	s_line
{
	t_pixel *a;
	t_pixel *b;
}				t_line;

typedef struct	s_part
{
	t_line	l;
	t_list	*part;
	t_list	*scnd;
	t_list	*list;
	t_list	*tmp;
	int		i;
}				t_part;

typedef struct	s_mouse
{
	int		curx;
	int		cury;
	int		prevx;
	int		prevy;
	int		x1;
	int		y1;
	char	draw_button;
	char	pressed;
}				t_mouse;

typedef struct	s_options
{
	double	x0;
	double	y0;
	double	z0;
	double	iso_scale;
	double	size;
	double	scale;
	int		max;
	int		min;
	int		horiz;
	int		vertic;
	int		altitude;
	int		x;
	char	proection;
}				t_options;

typedef struct	s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			col;
	int			row;
	int			decreaser;
	int			color_changer;
	int			color;
	t_calc		res;
	t_pixel		angle;
	t_pixel		first;
	t_pixel		second;
	t_mouse		mouse;
	t_img		*image;
	t_options	*options;
	t_list		*lines;
	t_list		*drawn;
}				t_fdf;

/*
** utilities.c
*/
void			ft_display_error(int condition, int i);
void			ft_free_args(char ***args, int i);
void			ft_calculate_angles(t_fdf *fdf);
int				ft_red_cross(void *param);
void			ft_draw_with_rmb(int x, int y, t_fdf *fdf);
/*
** initialize.c
*/
void			ft_initialize_fdf(t_fdf *fdf);
void			ft_initialize_map(t_fdf *fdf);
void			ft_set_defaults(t_fdf *fdf);
/*
** map_reader.c
*/
void			ft_read_map(int fd, t_list **lst, t_fdf *fdf);
/*
** image.c
*/
void			ft_set_pixel_to_image(t_fdf *fdf, int x, int y, int color);
void			ft_initialize_image(t_fdf *fdf);
void			ft_clear_image(t_img *image);
/*
** print_map.c
*/
void			ft_print_map(t_fdf fdf);
/*
** hooks.c
*/
int				ft_key_press(int keycode, t_fdf *fdf);
int				ft_mouse_press(int button, int x, int y, t_fdf *fdf);
int				ft_mouse_release(int button, int x, int y, t_fdf *fdf);
int				ft_mouse_move(int x, int y, t_fdf *fdf);
/*
** rotation.c
*/
void			ft_rotate_dots(t_pixel *pixel, t_calc res, t_fdf *fdf);
/*
** color.c
*/
int				ft_get_color(t_putline current, t_pixel start, t_pixel end);
/*
** bonus_things.c
*/
void			ft_init_decreaser(t_fdf *fdf);
void			ft_change_color(t_fdf *fdf);
void			ft_put_string_to_window(t_fdf fdf);
#endif
