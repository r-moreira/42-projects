/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_funct_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:56:07 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/08 12:56:07 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	ft_print_string_arg(char *arg_str, int len)
{
	int			index;
	char		null_str[7];

	index = -1;
	if (arg_str == NULL)
	{
		ft_strlcpy(null_str, "(null)", 7);
		while (++index < len)
			ft_putchar_fd(null_str[index], 1);
	}
	else
		while (++index < len)
			ft_putchar_fd(arg_str[index], 1);
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
	ft_print_string_arg(type.u_char_ptr, len);
	if (tools.opts.width > (len) && tools.flags.minus)
		ft_print_width(tools, len);
	return (tools.opts.width > len ? tools.opts.width : len);
}
