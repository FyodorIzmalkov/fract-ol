/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:57:02 by lsandor-          #+#    #+#             */
/*   Updated: 2018/11/28 14:24:35 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	i1;
	size_t	i2;
	char	*ret;

	i = -1;
	i1 = 0;
	i2 = 0;
	ret = NULL;
	if (s1 && s2)
	{
		i1 = ft_strlen(s1);
		i2 = ft_strlen(s2);
		if (!(ret = (char *)malloc(sizeof(char) * i1 + i2 + 1)))
			return (NULL);
		while (++i < i1 + i2)
		{
			if (i < i1)
				ret[i] = s1[i];
			else
				ret[i] = s2[i - i1];
		}
		ret[i] = '\0';
	}
	return (ret);
}
