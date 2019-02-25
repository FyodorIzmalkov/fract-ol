/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 23:22:38 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/15 19:33:47 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	t_list	*ft_get_lines(t_list **lst, int width)
{
	t_part x;

	x.i = 1;
	x.list = *lst;
	x.part = NULL;
	while (x.list)
	{
		x.l.a = x.list->content;
		if ((x.scnd = ft_lst_n(x.list, width)))
		{
			x.l.b = x.scnd->content;
			ft_display_error(!(x.tmp = ft_lstnew(&x.l, sizeof(t_line))), 3);
			ft_lstadd(&x.part, x.tmp);
		}
		if (x.i % width != 0)
			if ((x.scnd = ft_lst_n(x.list, 1)))
			{
				x.l.b = x.scnd->content;
				ft_display_error(!(x.tmp = ft_lstnew(&x.l, sizeof(t_line))), 3);
				ft_lstadd(&x.part, x.tmp);
			}
		x.i++;
		x.list = x.list->next;
	}
	return (x.part);
}

static	void	ft_save_coordinats(char **args, t_list **lst, int y, t_fdf *fdf)
{
	int		x;
	t_pixel	pixel;
	t_list	*tmp;
	size_t	struct_size;

	struct_size = sizeof(t_pixel);
	x = -1;
	while (args[++x])
	{
		pixel.x = x;
		pixel.y = y;
		pixel.z = ft_atoi(args[x]);
		if (pixel.z > fdf->options->max)
			fdf->options->max = pixel.z;
		else if (pixel.z < fdf->options->min)
			fdf->options->min = pixel.z;
		ft_display_error(!(tmp = ft_lstnew(&pixel, struct_size)), 3);
		ft_lstadd(lst, tmp);
	}
}

static	int		ft_count_width(char **line_args)
{
	int	i;

	i = 0;
	while (line_args[i])
		i++;
	return (i);
}

void			ft_read_map(int fd, t_list **lst, t_fdf *fdf)
{
	char	*gnl;
	char	**line_args;

	while (get_next_line(fd, &gnl) > 0)
	{
		ft_display_error(!(line_args = ft_strsplit(gnl, ' ')), 3);
		if (fdf->col == -1)
			fdf->col = ft_count_width(line_args);
		ft_display_error((fdf->col != ft_count_width(line_args)), 4);
		ft_save_coordinats(line_args, lst, fdf->row, fdf);
		ft_free_args(&line_args, fdf->col);
		fdf->row++;
	}
	fdf->lines = ft_get_lines(lst, fdf->col);
}
