/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_output_len_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:10:05 by romoreir          #+#    #+#             */
/*   Updated: 2020/10/11 22:17:41 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_bonus.h"

int		ft_get_output_len(char *arg_str, t_conversion tools)
{
	int len;

	len = ft_strlen(arg_str);
	if (len == 1 && arg_str[0] == '0' && tools.opts.precision == 0)
		return (0);
	return (len);
}
