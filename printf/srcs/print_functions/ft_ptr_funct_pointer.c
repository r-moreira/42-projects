/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_funct_pointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:12:21 by romoreir          #+#    #+#             */
/*   Updated: 2020/09/20 14:12:21 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int ft_handle_zero_input(t_arg_types type, t_conversion tools)
{
	int		len;
	int		width_len;

	if (type._luint != 0)
		return (0);
	len = ft_strlen("(nil)");
	width_len = tools.opts.width;
	if (PAD_LEFT(len))
		while (width_len-- > len)
			ft_putchar_fd(' ', 1);
	ft_putstr_fd("(nil)", 1);
	if (PAD_RIGTH(len))
		while (width_len-- > len)
			ft_putchar_fd(' ', 1);
	return (len > tools.opts.width ? len : tools.opts.width);
}

int			ft_ptr_funct_pointer(va_list *args, t_conversion tools)
{
	t_arg_types	type;
	char		*arg_str;
	int			len;

	type._luint = (long unsigned int)va_arg(*args, void *);
	if (type._luint == 0)
		return (ft_handle_zero_input(type, tools));
	arg_str = ft_nbr_to_str(LOWER_HEXA, type, tools);
	len = ft_strlen(arg_str) + 2;
	if (ZERO_FLAG)
		ft_putstr_fd("0x", 1);
	if (PAD_LEFT(len))
		ft_print_width(tools, len);
	if (!(ZERO_FLAG))
		ft_putstr_fd("0x", 1);
	ft_print_precision(tools, len - 2);
	len ? ft_putstr_fd(arg_str, 1) : len;
	free(arg_str);
	if (PAD_RIGTH(len))
		ft_print_width(tools, len);
	if (tools.opts.width > tools.opts.precision && tools.opts.width > len)
		return (tools.opts.width);
	else if (tools.opts.precision > len)
		return (tools.opts.precision + 2);
	return (len);
}
