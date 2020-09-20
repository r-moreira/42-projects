/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_input_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:10:13 by romoreir          #+#    #+#             */
/*   Updated: 2020/09/20 14:10:13 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	check_flags(const char *str, int i)
{
	if (IS_FLAG(str[i]))
		while (IS_FLAG(str[i]))
			i++;
	if ((!IS_OPTN(str[i])) && (!ft_isdigit(str[i])) && (!IS_CONV(str[i])))
		return (-1);
	return (i);
}

static int	check_width(const char *str, int i)
{
	if (IS_STAR(str[i]))
		i++;
	else if (ft_isdigit(str[i]))
		while (ft_isdigit(str[i]))
			i++;
	if ((!IS_PREC(str[i])) && (!IS_CONV(str[i])))
		return (-1);
	return (i);
}

static int	check_precision(const char *str, int i)
{
	if (IS_PREC(str[i]))
		i++;
	if ((!ft_isdigit(str[i])) && (!IS_STAR(str[i])) && (!IS_CONV(str[i])))
		return (-1);
	if (ft_isdigit(str[i]))
		while (ft_isdigit(str[i]))
			i++;
	else if (IS_STAR(str[i]))
		i++;
	if ((!IS_CONV(str[i])))
		return (-1);
	return (i);
}

int			ft_is_input_valid(const char *str)
{
	int		i;

	i = 0;
	if ((!IS_OPTN(str[i])) && (!ft_isdigit(str[i])) && (!IS_CONV(str[i])))
		return (0);
	if ((i = check_flags(str, i)) == -1)
		return (0);
	if ((i = check_width(str, i)) == -1)
		return (0);
	if ((i = check_precision(str, i)) == -1)
		return (0);
	if (!IS_CONV(str[i]))
		return (0);
	return (1);
}
