/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carpet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 23:53:29 by lsandor-          #+#    #+#             */
/*   Updated: 2019/03/03 22:08:47 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_if_filled(int x, int y)
{
	while (x > 0 || y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (0);
		x /= 3;
		y /= 3;
	}
	return (1);
}

void		ft_carpet(t_args *a)
{
	int	x;

	(*a->m->scale) >= 5 ? (*a->m->scale) = 1.6 : 0;
	(*a->m->scale) <= 0.6 ? (*a->m->scale) = 1.6 : 0;
	x = -1;
	while (++x < W_WIDTH)
	{
		if (ft_if_filled(x / (*a->m->scale), a->y / (*a->m->scale)))
		{
			if (a->m->set == 0)
				*(int *)(a->m->add_ptr + (x + a->y * W_WIDTH) * 4) = 0x00FFFFFF;
			else if (a->m->set == 1)
				*(int *)(a->m->add_ptr + (x + a->y * W_WIDTH) * 4) = 0x0004eab8;
			else
				*(int *)(a->m->add_ptr + (x + a->y * W_WIDTH) * 4) = 0x00e20faa;
		}
	}
}
