/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_input_valid_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:10:13 by romoreir          #+#    #+#             */
/*   Updated: 2020/10/11 22:17:58 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_bonus.h"

static int	check_flags(const char *str, int i)
{
	while (ft_is_option(str[i]) == E_FLAG)
		i++;
	if ((ft_is_conversion(str[i])) && (ft_is_option(str[i])))
		return (-1);
	return (i);
}

static int	check_width(const char *str, int i)
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
	if ((i = check_flags(str, i)) == -1)
		return (0);
	if ((i = check_width(str, i)) == -1)
		return (0);
	if ((i = check_precision(str, i)) == -1)
		return (0);
	if (!ft_is_conversion(str[i]))
		return (0);
	return (1);
}
