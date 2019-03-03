/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carpet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 23:53:29 by lsandor-          #+#    #+#             */
/*   Updated: 2019/03/03 13:21:09 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int ft_if_filled(int x, int y)
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

void	ft_carpet(t_args *a, char *add_ptr)
{
	(*a->m->scale) >= 5 ? (*a->m->scale) = 1.6 : 0;
	(*a->m->scale) <= 0.6 ? (*a->m->scale) = 1.6 : 0;
	while (++a->x <W_WIDTH)
	{
		if (ft_if_filled(a->x / (*a->m->scale), a->y / (*a->m->scale)))
			ft_set_pixel(add_ptr, a->x, a->y, 0x00FFFFFF);
	}
}
