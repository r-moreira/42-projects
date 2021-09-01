/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:33:24 by romoreir          #+#    #+#             */
/*   Updated: 2021/07/19 17:47:30 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapped_list;
	t_list	*head;

	if (!lst)
		return (NULL);
	mapped_list = ft_lstnew(f(lst->content));
	head = mapped_list;
	while (lst)
	{
		if (lst->next)
		{
			mapped_list->next = ft_lstnew(f(lst->next->content));
			if (!mapped_list)
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
