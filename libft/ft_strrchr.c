/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:06:55 by lsandor-          #+#    #+#             */
/*   Updated: 2018/11/23 16:14:17 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*str;
	char	b;

	str = (char*)s;
	i = ft_strlen(s);
	b = (char)c;
	while (i > 0 && str[i] != b)
		i--;
	if (str[i] == b)
		return (str + i);
	else
		return (NULL);
}
