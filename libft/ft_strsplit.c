/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:04:52 by lsandor-          #+#    #+#             */
/*   Updated: 2018/12/04 14:45:33 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_length(char const *str, char c)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static	int		ft_count(char const *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

static	char	**ft_free(char **str, int j)
{
	int i;

	i = 0;
	while (i < j)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**str;

	i = -1;
	j = 0;
	if (!s || !(str = (char **)malloc(sizeof(*str) * (ft_count(s, c) + 1))))
		return (NULL);
	while (++i < ft_count(s, c))
	{
		k = 0;
		if (!(str[i] = ft_strnew(ft_length(&s[j], c) + 1)))
			return (ft_free(str, i));
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			str[i][k++] = s[j++];
		str[i][k] = '\0';
	}
	str[i] = 0;
	return (str);
}
