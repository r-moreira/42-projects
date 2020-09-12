/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:42:23 by romoreir          #+#    #+#             */
/*   Updated: 2020/01/27 19:42:40 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total;

	total = count * size;
	if (!total)
	{
		if (!(ptr = malloc(sizeof(NULL))))
			return (NULL);
		return (ft_memset(ptr, 0, sizeof(NULL)));
	}
	if (!(ptr = malloc(total)))
		return (NULL);
	return (ft_memset(ptr, 0, total));
}
