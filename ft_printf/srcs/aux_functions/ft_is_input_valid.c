/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_input_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:10:13 by romoreir          #+#    #+#             */
/*   Updated: 2020/11/06 13:28:21 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_check_flags(const char *str, int i)
{
	while (ft_is_option(str[i]) == E_FLAG)
		i++;
	if ((!ft_is_conversion(str[i])) && (!ft_is_option(str[i])))
		return (-1);
	return (i);
}

static int	ft_check_width(const char *str, int i)
{
	if (ft_is_option(str[i]) == E_STAR)
		i++;
	else if (ft_isdigit(str[i]))
		while (ft_isdigit(str[i]))
			i++;
	if ((ft_is_option(str[i]) != E_PREC) && (!ft_is_conversion(str[i])))
		return (-1);
	return (i);
}

static int	check_precision(const char *str, int i)
{
	if (ft_is_option(str[i]) == E_PREC)
		i++;
	if ((!ft_is_conversion(str[i])) && (ft_is_option(str[i]) != E_STAR) &&
		(!ft_isdigit(str[i])))
		return (-1);
	if (ft_isdigit(str[i]))
		while (ft_isdigit(str[i]))
			i++;
	else if (ft_is_option(str[i]) == E_STAR)
		i++;
	if ((!ft_is_conversion(str[i])))
		return (-1);
	return (i);
}

int			ft_is_input_valid(const char *str)
{
	int		i;

	i = 0;
	if ((!ft_is_conversion(str[i])) && (!ft_is_option(str[i])))
		return (0);
	if ((i = ft_check_flags(str, i)) == -1)
		return (0);
	if ((i = ft_check_width(str, i)) == -1)
		return (0);
	if ((i = ft_check_precision(str, i)) == -1)
		return (0);
	if (!ft_is_conversion(str[i]))
		return (0);
	return (1);
}
