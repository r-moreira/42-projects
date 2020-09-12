/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:31:07 by romoreir          #+#    #+#             */
/*   Updated: 2020/02/04 19:31:10 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	size_t	lst_size;

	lst_size = 0;
	if (!(lst))
		return (0);
	while (lst)
	{
		lst = lst->next;
		lst_size++;
	}
	return (lst_size);
}
