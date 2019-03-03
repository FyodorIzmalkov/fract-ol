/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 21:42:16 by lsandor-          #+#    #+#             */
/*   Updated: 2019/03/03 21:12:51 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	f;

	if (argc != 2)
		return (ft_exit_error(1));
	ft_check_fractol(&f, argv[1]);
	ft_initialize_fractol(&f);
	f.mlx_ptr = mlx_init();
	f.mlx_win = mlx_new_window(f.mlx_ptr, F_WIDTH, W_HEIGHT, argv[1]);
	ft_initialize_image(&f);
	ft_select_fractol(&f);
	mlx_hook(f.mlx_win, 2, 0, ft_key_press, &f);
	mlx_hook(f.mlx_win, 4, 0, ft_mouse_press, &f);
	mlx_hook(f.mlx_win, 6, 0, ft_mouse_move, &f);
	mlx_hook(f.mlx_win, 17, 0, ft_close, &f);
	mlx_loop(f.mlx_ptr);
	return (0);
}
