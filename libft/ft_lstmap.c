/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:38:26 by lsandor-          #+#    #+#             */
/*   Updated: 2018/12/04 15:18:14 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_freelst(t_list *lst)
{
	t_list *next_obj;

	while (lst)
	{
		next_obj = lst->next;
		free(lst->content);
		free(lst);
		lst = next_obj;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*obj;
	t_list	*temp;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	temp = f(lst);
	if (!(new = ft_lstnew(temp->content, temp->content_size)))
		return (NULL);
	obj = new;
	lst = lst->next;
	while (lst)
	{
		temp = f(lst);
		if (!(new->next = ft_lstnew(temp->content, temp->content_size)))
		{
			ft_freelst(obj);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (obj);
}
