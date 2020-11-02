/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:33:24 by romoreir          #+#    #+#             */
/*   Updated: 2020/02/06 20:29:09 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapped_list;
	t_list	*head;

	if (!lst)
		return (NULL);
	if (!(mapped_list = ft_lstnew(f(lst->content))))
		return (NULL);
	head = mapped_list;
	while (lst)
	{
		if (lst->next)
		{
			if (!(mapped_list->next = ft_lstnew(f(lst->next->content))))
			{
				ft_lstclear(&head, del);
				return (0);
			}
			mapped_list = mapped_list->next;
		}
		lst = lst->next;
	}
	mapped_list->next = NULL;
	return (head);
}
