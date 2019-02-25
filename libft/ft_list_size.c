/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 10:25:29 by lsandor-          #+#    #+#             */
/*   Updated: 2018/12/03 12:21:23 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int			ft_list_size(t_list *alst)
{
	int		i;
	t_list	*lst;

	i = 0;
	if (alst)
	{
		lst = alst;
		while (lst)
		{
			i++;
			lst = lst->next;
		}
	}
	return (i);
}
