/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:12:32 by lsandor-          #+#    #+#             */
/*   Updated: 2018/11/30 14:17:34 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	unsigned int	len;
	char			*ret;

	i = 0;
	len = 0;
	ret = NULL;
	if (s && f)
	{
		while (s[len] != '\0')
			len++;
		if (!(ret = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (s[i] != '\0')
		{
			ret[i] = f(s[i]);
			i++;
		}
		ret[i] = '\0';
	}
	return (ret);
}
