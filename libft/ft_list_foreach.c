/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 09:29:01 by lsandor-          #+#    #+#             */
/*   Updated: 2018/12/03 12:03:34 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_list_foreach(t_list *alst, void (*f)(void *, size_t))
{
	while (alst && f)
	{
		f(alst->content, alst->content_size);
		alst = alst->next;
	}
}
