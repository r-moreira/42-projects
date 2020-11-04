/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_funct_pointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:12:21 by romoreir          #+#    #+#             */
/*   Updated: 2020/11/03 23:32:31 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_handle_pointer_null_input()
{
	//refazer
	return (0);
}

int			ft_ptr_funct_pointer(va_list *args, t_conversion tools)
{
	t_arg_types	type;
	char		*arg_str;
	int			len;

	type.u_luint = (long unsigned int)va_arg(*args, void *);
	if (type.u_luint == 0)
		return (ft_handle_pointer_null_input());
	arg_str = ft_nbr_to_str(LOWER_HEXA, type, &tools);
	len = ft_strlen(arg_str) + 2;
	if (tools.flags.zero && tools.opts.precision == -1 && !tools.flags.minus)
		ft_putstr_fd("0x", 1);
	if (tools.opts.width > (len) && !tools.flags.minus)
		ft_print_width(tools, len);
	if (!(tools.flags.zero && tools.opts.precision == -1 && !tools.flags.minus))
		ft_putstr_fd("0x", 1);
	ft_print_precision(tools, len - 2);
	len ? ft_putstr_fd(arg_str, 1) : len;
	free(arg_str);
	if (tools.opts.width > (len) && tools.flags.minus)
		ft_print_width(tools, len);
	if (tools.opts.width > tools.opts.precision && tools.opts.width > len)
		return (tools.opts.width);
	else if (tools.opts.precision > len)
		return (tools.opts.precision + 2);
	return (len);
}
