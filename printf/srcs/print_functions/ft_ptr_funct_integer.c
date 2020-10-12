/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_funct_integer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:12:02 by romoreir          #+#    #+#             */
/*   Updated: 2020/10/12 00:33:44 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			ft_ptr_funct_integer(va_list *args, t_conversion tools)
{
	t_arg_types	type;
	char		*arg_str;
	int			len;

	if (tools.conv == 'd' || tools.conv == 'i')
		type.u_int = va_arg(*args, int);
	else
		type.u_uint = va_arg(*args, unsigned int);
	arg_str = ft_nbr_to_str(DECIMAL, type, tools);
	len = ft_strlen(arg_str);
	if (len == 1 && arg_str[0] == '0' && tools.opts.precision == 0)
		len = 0;
	if (tools.opts.width > (len) && !tools.flags.minus)
		ft_print_width(tools, len);
	ft_print_precision(tools, len);
	len > 0 ? ft_putstr_fd(arg_str, 1) : len;
	free(arg_str);
	if (tools.opts.width > (len) && tools.flags.minus)
		ft_print_width(tools, len);
	if (tools.opts.width > tools.opts.precision && tools.opts.width > len)
		return (tools.opts.width);
	else if (tools.opts.precision > len)
		return (tools.opts.precision);
	return (len);
}
