/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_funct_pointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:56:07 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/08 12:56:07 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_get_ptr_pointer_return(t_conversion tools, int len)
{
	if (tools.opts.width > tools.opts.precision && tools.opts.width > len)
		return (tools.opts.width);
	else if (tools.opts.precision > len)
		return (tools.opts.precision + 2);
	else if (tools.opts.precision == 2)
		return (len + 1);
	else if (tools.opts.precision == 3)
		return (len + 2);
	return (len);
}

int			ft_ptr_funct_pointer(va_list *args, t_conversion tools)
{
	t_arg_types	type;
	char		*arg_str;
	int			len;

	type.u_luint = (long unsigned int)va_arg(*args, void *);
	arg_str = ft_nbr_to_str(LOWER_HEXA, type, &tools);
	len = ft_strlen(arg_str) + 2;
	if (tools.opts.precision == 0)
		len--;
	if (tools.opts.width > (len) && !tools.flags.minus)
		ft_print_width(tools, len);
	ft_putstr_fd("0x", 1);
	ft_print_precision(tools, len - 2);
	if (type.u_luint)
		ft_putstr_fd(arg_str, 1);
	else if (tools.opts.precision)
		ft_putchar_fd('0', 1);
	free(arg_str);
	if (tools.opts.width > (len) && tools.flags.minus)
		ft_print_width(tools, len);
	return (ft_get_ptr_pointer_return(tools, len));
}
