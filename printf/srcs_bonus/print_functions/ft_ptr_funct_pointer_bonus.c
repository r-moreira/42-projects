/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_funct_pointer_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:12:21 by romoreir          #+#    #+#             */
/*   Updated: 2020/10/22 01:42:57 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_bonus.h"

static int	ft_handle_zero_input(t_arg_types type, t_conversion tools)
{
	int		len;
	int		width_len;

	if (type.u_luint != 0)
		return (0);
	len = ft_strlen("(nil)");
	width_len = tools.opts.width;
	if (tools.opts.width > (len) && !tools.flags.minus)
		while (width_len-- > len)
			ft_putchar_fd(' ', 1);
	ft_putstr_fd("(nil)", 1);
	if (tools.opts.width > (len) && tools.flags.minus)
		while (width_len-- > len)
			ft_putchar_fd(' ', 1);
	return (len > tools.opts.width ? len : tools.opts.width);
}

int			ft_ptr_funct_pointer(va_list *args, t_conversion tools)
{
	t_arg_types	type;
	char		*arg_str;
	int			len;

	type.u_luint = (long unsigned int)va_arg(*args, void *);
	if (type.u_luint == 0)
		return (ft_handle_zero_input(type, tools));
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
