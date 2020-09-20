/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_funct_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <romoreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:12:28 by romoreir          #+#    #+#             */
/*   Updated: 2020/09/20 14:12:28 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_ptr_funct_string(va_list *args, t_conversion tools)
{
	t_arg_types	type;
	int			index;
	int			len;

	index = -1;
	type._char_ptr = va_arg(*args, char *);
	len = ft_strlen(type._char_ptr);
	if (tools.opts.precision != -1 && tools.opts.precision < len)
		len = tools.opts.precision;
	if (PAD_LEFT(len))
		ft_print_width(tools, len);
	while (++index < len)
		ft_putchar_fd(type._char_ptr[index], 1);
	if (PAD_RIGTH(len))
		ft_print_width(tools, len);
	return (tools.opts.width > len ? tools.opts.width : len);
}
