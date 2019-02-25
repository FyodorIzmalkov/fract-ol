/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:09:12 by lsandor-          #+#    #+#             */
/*   Updated: 2018/11/30 14:17:53 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*ret;

	len = 0;
	ret = NULL;
	if (s && f)
	{
		while (s[len] != '\0')
			len++;
		if (!(ret = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		len = 0;
		while (s[len] != '\0')
		{
			ret[len] = f(len, s[len]);
			len++;
		}
		ret[len] = '\0';
	}
	return (ret);
}
