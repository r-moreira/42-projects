/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_funct_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:12:28 by romoreir          #+#    #+#             */
/*   Updated: 2020/10/31 01:31:03 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdio.h> //APAGAR

static int	ft_print_str_arg(t_conversion tools, char *str, int len)
{
	int			index;

	index = -1;
	if (str != NULL)
		while (++index < len)
			ft_putchar_fd(str[index], 1);
	else if (tools.opts.width && tools.opts.precision != -1 &&
	tools.opts.precision <= 6 && tools.opts.width > tools.opts.precision)
		while (tools.opts.precision--)
			ft_putchar_fd(' ', 1);
	else if (tools.opts.width && tools.opts.precision != -1 &&
	tools.opts.precision <= 6 && tools.opts.width < tools.opts.precision)
	{
		index = tools.opts.width;
		while (index--)
			ft_putchar_fd(' ', 1);
		return (tools.opts.width);
	}
	else if (!tools.opts.width && tools.opts.precision != -1 &&
			tools.opts.precision <= 6)
		return (0);
	else
		ft_putstr_fd("(null)", 1);
	return (len);
}

int			ft_ptr_funct_string(va_list *args, t_conversion tools)
{
	t_arg_types	type;
	int			len;

	type.u_char_ptr = va_arg(*args, char *);
	if (type.u_char_ptr == NULL)
		len = 6;
	else
		len = ft_strlen(type.u_char_ptr);
	if (tools.opts.precision != -1 && tools.opts.precision < len)
		len = tools.opts.precision;
	if (tools.opts.width > (len) && !tools.flags.minus)
		ft_print_width(tools, len);
	len = ft_print_str_arg(tools, type.u_char_ptr, len);
	if (tools.opts.width > (len) && tools.flags.minus)
		ft_print_width(tools, len);
	return (tools.opts.width > len ? tools.opts.width : len);
}
