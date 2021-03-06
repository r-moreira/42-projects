/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:10:23 by romoreir          #+#    #+#             */
/*   Updated: 2020/10/22 00:57:22 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char				*ft_make_str(unsigned long nbr, int sign, int base_len,
char *digits)
{
	unsigned long	temp;
	char			*str;
	int				digits_len;

	temp = nbr;
	digits_len = 0;
	sign == -1 ? digits_len++ : digits_len;
	while (temp > 0)
	{
		temp /= base_len;
		digits_len++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (digits_len + 1))))
		return (NULL);
	if (sign == -1)
		str[0] = '-';
	str[digits_len] = '\0';
	while (nbr > 0)
	{
		str[--digits_len] = digits[nbr % base_len];
		nbr /= base_len;
	}
	return (str);
}

static unsigned long	ft_get_arg_nbr(t_arg_types arg, t_conversion *tools)
{
	unsigned long	nbr;
	long			snbr;

	if (tools->conv == 'd' || tools->conv == 'i')
	{
		if (arg.u_int < 0)
			tools->sign = -1;
		snbr = arg.u_int;
		if (snbr < 0)
			nbr = -(snbr);
		else
			nbr = snbr;
	}
	else if (tools->conv == 'u' || tools->conv == 'x' || tools->conv == 'X')
		nbr = arg.u_uint;
	else
		nbr = arg.u_luint;
	return (nbr);
}

char					*ft_nbr_to_str(int base, t_arg_types arg,
t_conversion *tools)
{
	unsigned long	nbr;
	int				base_len;

	nbr = ft_get_arg_nbr(arg, tools);
	if (base == LOWER_HEXA || base == UPPER_HEXA)
		base_len = 16;
	else
		base_len = 10;
	if (nbr == 0)
		return (ft_strdup("0"));
	if (base == DECIMAL)
		return (ft_make_str(nbr, tools->sign, base_len, "0123456789"));
	if (base == LOWER_HEXA)
		return (ft_make_str(nbr, tools->sign, base_len, "0123456789abcdef"));
	if (base == UPPER_HEXA)
		return (ft_make_str(nbr, tools->sign, base_len, "0123456789ABCDEF"));
	return (NULL);
}
