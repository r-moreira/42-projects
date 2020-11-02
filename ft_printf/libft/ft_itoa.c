/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 14:03:18 by romoreir          #+#    #+#             */
/*   Updated: 2020/02/02 15:03:54 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_get_nbrlen(long nbr, int sign)
{
	size_t	len;

	len = 0;
	if (nbr == 0)
		return (len = 1);
	if (sign == -1)
		len++;
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static void	ft_convert_str(char *str, long nbr, int sign, size_t len)
{
	if (sign == -1)
		str[0] = '-';
	str[len] = '\0';
	if (nbr == 0)
	{
		str[--len] = nbr % 10 + 48;
		nbr /= 10;
	}
	else
	{
		while (nbr > 0)
		{
			str[--len] = (nbr % 10) + 48;
			nbr /= 10;
		}
	}
}

char		*ft_itoa(int n)
{
	char			*str;
	int				sign;
	long			nbr;
	size_t			len;

	sign = 1;
	if (n < 0)
		sign = -1;
	nbr = (long)n * sign;
	len = ft_get_nbrlen(nbr, sign);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_convert_str(str, nbr, sign, len);
	return (str);
}
