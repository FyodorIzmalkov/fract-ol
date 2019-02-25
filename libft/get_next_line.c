/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:05:50 by lsandor-          #+#    #+#             */
/*   Updated: 2018/12/13 13:39:19 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	t_file	*ft_check_fd(t_file **file, int fd)
{
	t_file	*temp;

	temp = *file;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	if (!(temp = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	if (!(temp->data = ft_strnew(0)))
		return (NULL);
	temp->fd = fd;
	temp->next = *file;
	*file = temp;
	return (temp);
}

static	char	*ft_make_str(char **data, char *buf)
{
	char	*result;

	if (!(result = ft_strjoin(*data, buf)))
		return (NULL);
	ft_strdel(data);
	return (result);
}

static	char	*ft_return_line(char **data)
{
	char	*result;
	char	*temp;
	size_t	i;

	i = 0;
	if (!(temp = ft_strdup(*data)))
		return (NULL);
	while (temp[i] != '\n' && temp[i])
		i++;
	if (!(result = ft_strnew(i)))
		return (NULL);
	ft_strncpy(result, *data, i);
	ft_strdel(data);
	if (i < ft_strlen(temp))
	{
		if (!(*data = ft_strdup(temp + i + 1)))
			return (NULL);
	}
	else
	{
		if (!(*data = ft_strdup("\0")))
			return (NULL);
	}
	ft_strdel(&temp);
	return (result);
}

int				get_next_line(const int fd, char **line)
{
	static	t_file	*file;
	t_file			*cur;
	int				ln;
	char			buf[BUFF_SIZE + 1];

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (!(cur = ft_check_fd(&file, fd)))
		return (-1);
	ln = 0;
	while (!(ft_strchr(cur->data, '\n')) && (ln = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ln] = '\0';
		if (!(cur->data = ft_make_str(&cur->data, buf)))
			return (-1);
		if (ft_strchr(cur->data, '\n'))
			break ;
	}
	if (ln < BUFF_SIZE && !(ft_strlen(cur->data)))
		return (0);
	if (!(*line = ft_return_line(&cur->data)))
		return (-1);
	return (1);
}
