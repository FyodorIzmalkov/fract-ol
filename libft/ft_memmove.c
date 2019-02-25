/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 11:44:42 by lsandor-          #+#    #+#             */
/*   Updated: 2018/11/30 15:11:04 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *source;
	char *destin;

	if (!dst && !src)
		return (NULL);
	source = (char *)src;
	destin = (char *)dst;
	if (source < destin)
	{
		while (len > 0)
		{
			len--;
			destin[len] = source[len];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
