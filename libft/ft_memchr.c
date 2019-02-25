/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:39:30 by lsandor-          #+#    #+#             */
/*   Updated: 2018/11/23 12:46:44 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	b;
	unsigned char	*ret;
	size_t			i;

	i = 0;
	ret = (unsigned char*)s;
	b = (unsigned char)c;
	while (i < n)
	{
		if (ret[i] == b)
			return (ret + i);
		i++;
	}
	return (NULL);
}
