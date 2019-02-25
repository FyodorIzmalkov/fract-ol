/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 09:32:34 by lsandor-          #+#    #+#             */
/*   Updated: 2018/12/03 11:53:02 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_list_reverse(t_list *alst)
{
	t_list	*prev;
	t_list	*curr;
	t_list	*next;

	prev = NULL;
	next = NULL;
	curr = alst;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	alst = prev;
	return (alst);
}
