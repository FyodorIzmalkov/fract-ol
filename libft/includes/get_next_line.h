/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:01:43 by lsandor-          #+#    #+#             */
/*   Updated: 2019/02/07 16:08:21 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE 1024

typedef struct		s_file
{
	char			*data;
	int				fd;
	struct s_file	*next;
}					t_file;

int					get_next_line(const int fd, char **line);
#endif
