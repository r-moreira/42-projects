/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:56:07 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/08 12:56:07 by romoreir         ###   ########.fr       */
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
