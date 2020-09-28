/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_funct_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:12:28 by romoreir          #+#    #+#             */
/*   Updated: 2020/09/20 19:35:02 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_ptr_funct_string(va_list *args, t_conversion tools)
{
	t_arg_types	type;
	int			index;
	int			len;

	index = -1;
	type.u_char_ptr = va_arg(*args, char *);
	len = ft_strlen(type.u_char_ptr);
	if (tools.opts.precision != -1 && tools.opts.precision < len)
		len = tools.opts.precision;
	if (tools.opts.width > (len) && !tools.flags.minus)
		ft_print_width(tools, len);
	while (++index < len)
		ft_putchar_fd(type.u_char_ptr[index], 1);
	if (tools.opts.width > (len) && tools.flags.minus)
		ft_print_width(tools, len);
	return (tools.opts.width > len ? tools.opts.width : len);
}
