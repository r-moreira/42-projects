/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_funct_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:12:28 by romoreir          #+#    #+#             */
/*   Updated: 2020/11/01 02:18:22 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	ft_print_null_space(int index)
{
	while (index--)
		ft_putchar_fd(' ', 1);
}

static int	ft_handle_null_input(t_conversion tools, int len)
{
	if (!tools.opts.width && tools.opts.precision == -1)
	{
		ft_putstr_fd("(null)", 1);
		return (len);
	}
	if (!tools.opts.width && tools.opts.precision != -1 &&
	tools.opts.precision < 6)
		return (0);
	if (tools.opts.width > tools.opts.precision && tools.opts.precision != -1
	&& tools.opts.precision < 6)
	{
		ft_print_null_space(tools.opts.width - (tools.opts.width -
		tools.opts.precision));
		return (len);
	}
	if (tools.opts.precision > tools.opts.width && tools.opts.width
	&& tools.opts.precision < 6)
	{
		ft_print_null_space(tools.opts.precision - tools.opts.width);
		return (tools.opts.precision - tools.opts.width);
	}
	if (tools.opts.precision || tools.opts.width)
		ft_putstr_fd("(null)", 1);
	return (len);
}

static int	ft_print_str_arg(t_conversion tools, char *str, int len)
{
	int			index;

	index = -1;
	if (str != NULL)
	{
		while (++index < len)
			ft_putchar_fd(str[index], 1);
		return (len);
	}
	return (ft_handle_null_input(tools, len));
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
