/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 19:45:03 by romoreir          #+#    #+#             */
/*   Updated: 2021/07/19 17:38:23 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *destination, const char *source)
{
	char	*ptr;

	ptr = destination + ft_strlen(destination);
	while (*source != '\0')
	{
		*ptr++ = *source++;
	}
	*ptr = '\0';
	return (destination);
}
