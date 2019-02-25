/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:45:14 by lsandor-          #+#    #+#             */
/*   Updated: 2018/11/28 13:56:46 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*ret;

	i = 0;
	ret = NULL;
	if (s)
	{
		if (!(ret = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (s[start] != '\0' && i < len)
		{
			ret[i] = s[start + i];
			i++;
		}
		ret[i] = '\0';
	}
	return (ret);
}
