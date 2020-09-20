/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:42:02 by romoreir          #+#    #+#             */
/*   Updated: 2020/09/20 19:42:02 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		ft_is_option(char c)
{
	if (c == '*')
		return (E_STAR);
	if (c == '.')
		return (E_PREC);
	if (c == '0' || c == '-')
		return (E_FLAG);
	if (ft_isdigit(c))
		return (E_DIGIT);
	return (E_FALSE);
}

int		ft_is_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' ||
		c == 'x' || c == 'X' || c == '%')
		return (E_CONV);
	return (E_FALSE);
}
