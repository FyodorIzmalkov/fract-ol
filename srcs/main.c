/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:57:57 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/15 16:58:10 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_list	*lst;
	t_fdf	fdf;

	ft_display_error(argc != 2, 1);
	fd = open(argv[1], O_RDONLY);
	ft_display_error((fd < 0), 2);
	ft_initialize_fdf(&fdf);
	ft_read_map(fd, &lst, &fdf);
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, W_WIDTH, W_HEIGHT, argv[1]);
	ft_initialize_map(&fdf);
	ft_initialize_image(&fdf);
	mlx_hook(fdf.win_ptr, 2, 0, ft_key_press, &fdf);
	mlx_hook(fdf.win_ptr, 4, 0, ft_mouse_press, &fdf);
	mlx_hook(fdf.win_ptr, 5, 0, ft_mouse_release, &fdf);
	mlx_hook(fdf.win_ptr, 6, 0, ft_mouse_move, &fdf);
	mlx_hook(fdf.win_ptr, 17, 0, ft_red_cross, &fdf);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}
