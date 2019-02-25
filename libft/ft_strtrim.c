/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:02:15 by lsandor-          #+#    #+#             */
/*   Updated: 2018/11/30 17:08:58 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strtrim(const char *s)
{
	char	*ret;
	int		i;
	int		len;

	if (s == NULL)
		return (NULL);
	while ((*s == ' ' || *s == '\t' || *s == '\n') && *s)
		s++;
	if (*s == '\0')
		return (ft_strnew(1));
	len = ft_strlen(s) - 1;
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		len--;
	len++;
	if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len)
		ret[i] = s[i];
	ret[i] = '\0';
	return (ret);
}
