/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_funct_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:12:28 by romoreir          #+#    #+#             */
/*   Updated: 2020/11/04 18:50:39 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_handle_str_null_input()
{
	//refazer
	return (0);
}

int			ft_ptr_funct_string(va_list *args, t_conversion tools)
{
	t_arg_types	type;
	int			len;
	int			index;

	index = -1;
	type.u_char_ptr = va_arg(*args, char *);
	if (type.u_char_ptr == NULL)
		return (ft_handle_str_null_input());
	else
		len = ft_strlen(type.u_char_ptr);
	if (tools.opts.precision != -1 && tools.opts.precision < len)
		len = tools.opts.precision;
	if (tools.opts.width > (len) && !tools.flags.minus)
		ft_print_width(tools, len);
	index = -1;
	while (++index < len)
		ft_putchar_fd(type.u_char_ptr[index], 1);
	if (tools.opts.width > (len) && tools.flags.minus)
		ft_print_width(tools, len);
	return (tools.opts.width > len ? tools.opts.width : len);
}
