/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:40:36 by lsandor-          #+#    #+#             */
/*   Updated: 2018/11/30 17:14:43 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				sign;
	long long int	ret;
	long long int	tmp;

	sign = 0;
	ret = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\v' || *str == '\r' || *str == '\f')
		str++;
	if (*str == '-')
		sign = 1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		tmp = ret;
		ret = ret * 10;
		ret += (int)(*str) - '0';
		if (ret < tmp)
			return (sign == 1 ? 0 : -1);
		str++;
	}
	return (sign == 1 ? -ret : ret);
}
